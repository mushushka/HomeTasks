 //
// Created by Елена Сермягина on 19.10.2017.
//

#ifndef KVATERNION_KVATERNION_H
#define KVATERNION_KVATERNION_H

#include <iosfwd>

struct Kvaternion
{
    Kvaternion() = default;
    ~Kvaternion() = default;
    Kvaternion( const double _i1, const double _i2, const double _j1, const double _j2);
    Kvaternion(Kvaternion& kva);

    double i11{0.0};
    double i12{0.0};
    double i21{0.0};
    double i22{0.0};

    Kvaternion& operator*=(Kvaternion& kva);
    double Determinator(Kvaternion& kva);


    std::ostream& writeTo(std::ostream& ostrm) const;



};

std::ostream& operator<<(std::ostream& ostr, Kvaternion kva);

#endif //KVATERNION_KVATERNION_H

