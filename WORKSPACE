load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "com_google_googletest",
    remote = "https://github.com/google/googletest",
    tag = "release-1.8.1",
)

# Use these commands in the terminal
# use this to create binaries for main.cpp
# bazel build //src/main:main 

# run the binary file  
# bazel-bin\src\main\main.exe

# instead of the 2 above you can just use
# bazel run src/main:main 
# to build and run at once

# to run tests use
# bazel test tests:test
# it will automatically download google test

# Test logs are in 
# bazel-testlogs\tests\test\test.log