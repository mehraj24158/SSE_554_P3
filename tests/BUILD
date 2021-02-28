load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "test",
    # srcs = glob(["**/*.cpp"]),
    srcs = ["test_main.cpp"],
    deps = [
        "//src/lib:car-lib",
        "@com_google_googletest//:gtest_main",
    ],
)