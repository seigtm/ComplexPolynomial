from conans import ConanFile


class Polynomial(ConanFile):
    name = "Polynomial With Complex Coefficients"
    version = "1.0.0"
    author = "Baranov Konstantin (seigtm@gmail.com)"
    url = "https://github.com/seigtm/Polynomial"
    description = "Test of the polynomial class whose coefficients are complex numbers"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    requires = \
        "boost/[1.77.0]", "Polynomial/[~1.0.4]", "Complex/[~1.4.0]"

    build_requires = \
        "gtest/[1.11]"
