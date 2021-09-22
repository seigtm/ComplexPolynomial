from conans import ConanFile


class Polynomial(ConanFile):
    name = "Polynomial With Complex Coefficients"
    version = "1.0.1"
    author = "Baranov Konstantin (seigtm@gmail.com)"
    url = "https://github.com/seigtm/Polynomial"
    description = "Test of the polynomial class whose coefficients are complex numbers"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    requires = \
        "Polynomial/[~1.0.4]", "Complex/[~1.4.0]"

    build_requires = \
        "gtest/[1.11]"
