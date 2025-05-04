#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")
env.Append(LIBPATH=["libs/"])

if env["platform"] == "windows":
    env.Append(LIBS=["User32"])
    env.Append(CPPDEFINES=['OS_WIN', 'SUNVOX_MAIN'])
    env.Append(CCFLAGS=['/std:c++20'])
    library = env.SharedLibrary(
        "project/bin/libtlccpp{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )
elif env["platform"] == "linux":
    env.Append(CPPDEFINES=['OS_LINUX', 'SUNVOX_MAIN'])
    env.Append(CCFLAGS=['-ldl -std=c++20'])
    library = env.SharedLibrary(
        "project/bin/libtlccpp{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "project/bin/libtlccpp{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )
Default(library)
