//
// Created by Robert on 07/12/2021.
//

#include "Coefficient.h"
#include "FourierAnalysis.h"

Coefficient::Coefficient(const double& F, const double& G): F(F), G(G) {}

Coefficient::Coefficient(const std::pair<double, double>& that): F(that.first), G(that.second) {}

Coefficient Coefficient::conjugate() const {
    return Coefficient(F, -G);
}
