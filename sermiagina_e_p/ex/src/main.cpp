
#include <dlib/opencv.h>
#include <opencv2/highgui/highgui_c.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <opencv2/videoio.hpp>
#include <opencv/cv.hpp>

void overlayImage(const cv::Mat &background, const cv::Mat &foreground,
                  cv::Mat &output, cv::Point2i location, double width, double deltaHeight, double deltaWidth) {

    //центрирование и установка требуемого начального положения
    location.x = int(location.x - width / 2 + deltaWidth);
    location.y = int(location.y - deltaHeight);


    //копирование исходного изображения
    background.copyTo(output);

    for (int y = std::max(location.y, 0); y < background.rows; y += 1) {
        int fY = y - location.y;


        if (fY >= foreground.rows) {
            break;
        }


        for (int x = cv::max(location.x, 0); x < background.cols; x += 1) {
            int fX = x - location.x;

            if (fX >= foreground.cols) {
                break;
            }

            // определение прозрачности с помощью  4 (альфа) канала
            double opacity = ((double) foreground.data[fY * foreground.step + fX * foreground.channels() + 2]) / 255.0;


            //объединение кадра и маски с учетом прозрачности
            for (int c = 0; opacity > 0 && c < output.channels(); c += 1) {
                unsigned char foregroundPx =
                        foreground.data[fY * foreground.step + fX * foreground.channels() + c];
                unsigned char backgroundPx =
                        background.data[y * background.step + x * background.channels() + c];
                output.data[y * output.step + output.channels() * x + c] =
                        uchar(backgroundPx * (1.0 - opacity) + foregroundPx * opacity);

            }
        }
    }
}


int main() {

    //переменная detector типа frontal_face_detector :  оператор () возвращает вектор прямоугольников (std::vector<dlib::rectangle>)
    dlib::frontal_face_detector detector = dlib::get_frontal_face_detector();
    //переменная predictor типа shape_predictor :  оператор () возвращает экзепляр класса full_object_detection
    //который содержит вектор точек х,у  (std::vector<point>)
    dlib::shape_predictor predictor;
    //данный файл можно найти по ссылке: http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2
    dlib::deserialize("shape_predictor_68_face_landmarks.dat") >> predictor;

    //инициализация захвата кадра
    cv::VideoCapture capture(0);
    if (!capture.isOpened()) {
        std::cout << "Unable to connect to camera" << std::endl;
        return 1;
    }
    //установка количества кадров в секунду
    capture.set(CV_CAP_PROP_FPS, 10);
    //задание путей до масок
    cv::String pathToMask = "./images/beard.png";
    cv::String pathToHat = "./images/hat.png";
    //чтение масок
    cv::Mat overlayMask = imread(pathToMask);
    cv::Mat overlayHat = imread(pathToHat);

    //пока идет чтение кадра
    while (capture.isOpened()) {
        //создрание кадра типа cv::Mat
        cv::Mat frame;
        //захват кадра
        capture >> frame;
        //создание допольнительной копии кадра для последующего наложения маоск и вывода на экран
        cv::Mat result = frame;
        //задание качества
        capture.set(cv::CAP_PROP_FRAME_WIDTH, 240);

        //изменение цветового диапазона на черно-белый для более быстрого распознавания лиц
        cv::Mat gray;
        cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

        dlib::cv_image<unsigned char> dlib_img(gray);

        //создание вектора с прямоугольниками-лицами
        std::vector<dlib::rectangle> faces = detector(dlib_img, 0);

        // с++11 цикл for по заданному контейнеру
        for (dlib::rectangle face : faces) {

            //отрисовка лиц прямоугольниками
//             cv::rectangle( frame, cv::Point(face.left(),face.top()), cv::Point( face.right(),face.bottom()), cv::Scalar(139,75,95 ), +2, 4 );

            //разпознавание 68 опорных точек лица
            dlib::full_object_detection shape = predictor(dlib_img, face);

            //длина и ширина лица
            double faceWidth = shape.part(15).x() - shape.part(3).x();
            double faceHeight = shape.part(9).y() - shape.part(25).y();
            //опорные точки масок
            cv::Point location = cv::Point((int) shape.part(34).x(), (int) shape.part(34).y());
            cv::Point locationHat = cv::Point((int) shape.part(28).x(), (int) shape.part(28).y());
            cv::Mat tempMask = overlayMask;
            cv::Mat tempHat = overlayHat;
            cv::Size maskSize = tempMask.size();
            cv::Size hatSize = tempHat.size();
            //изменение размеров и отрисовка масок с объединением в одно изображение
            cv::resize(overlayMask, tempMask, cv::Size(), faceWidth / maskSize.width, faceHeight / maskSize.height);
            maskSize = tempMask.size();
            overlayImage(frame, tempMask, result, location, maskSize.width,
                         (shape.part(52).y() - shape.part(34).y()), -7);

            cv::resize(overlayHat, tempHat, cv::Size(), (faceWidth / hatSize.width) * 1.6,
                       (faceHeight / hatSize.height));
            hatSize = tempHat.size();
            overlayImage(frame, tempHat, result, locationHat, hatSize.width,
                         (1.5 * (shape.part(9).y() - shape.part(28).y())), +20);
//отрисовка 68 точек лица

//            for (unsigned long i = 1; i < shape.num_parts(); i += 1) {
//                std::cout << shape.part(i) << std::endl;
//                int x_point = (int) shape.part(i).x();
//                int y_point = (int) shape.part(i).y();
//                cv::Point xy = cv::Point(x_point, y_point);
//                cv::circle(result, xy, 1, cv::Scalar(139, 75, 95), -1);
//            }
        }
//прекращение работы программы при нажатии escape и сохранение кадра
        auto c = (char) cv::waitKey(1);
        if (c == 13) {
            imwrite("Masks.jpg",result);
        } else if (c == 27) {
            std::cout << "escape" << std::endl;
            break;
        }

        imshow("Frame", result);
    }

    // очищение памяти
    capture.release();

    // уничтожение окон
    cv::destroyAllWindows();

    return 0;
}



