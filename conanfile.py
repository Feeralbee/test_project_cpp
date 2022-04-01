from conans import ConanFile, CMake

class NitroPro(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "cmake_multi"

    # comma-separated list of requirements that apply to all OS
    requires = ()


    def requirements(self):
        self.requires("gtest/1.11.0#0f1a3d5066001a8dde6535bf5b487fdd")


