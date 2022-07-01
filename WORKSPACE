load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "gtest",
    urls = [
        "https://github.com/google/googletest/archive/release-1.10.0.zip",
    ],
    sha256 = "94c634d499558a76fa649edb13721dce6e98fb1e7018dfaeba3cd7a083945e91",
    strip_prefix = "googletest-release-1.10.0",
)

http_archive(
    name = "benchmark",
    urls = [
        "https://github.com/google/benchmark/archive/refs/tags/v1.5.5.zip",
    ],
    sha256 = "30f2e5156de241789d772dd8b130c1cb5d33473cc2f29e4008eab680df7bd1f0",
    strip_prefix = "benchmark-1.5.5",
)

# Hedron's Compile Commands Extractor for Bazel
# https://github.com/hedronvision/bazel-compile-commands-extractor
http_archive(
    name = "hedron_compile_commands",
    sha256 = "e6f49fa7e1b0f7cb80c797916f6693305a852cf51ab1bd5797061ece3039e212",
    # Replace the commit hash in both places (below) with the latest, rather than using the stale one here.
    # Even better, set up Renovate and let it do the work for you (see "Suggestion: Updates" in the README).
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/13e135934b0f3bf1b71982e512cbe1cb11f6414f.tar.gz",
    strip_prefix = "bazel-compile-commands-extractor-13e135934b0f3bf1b71982e512cbe1cb11f6414f",
    # When you first run this tool, it'll recommend a sha256 hash to put here with a message like: "DEBUG: Rule 'hedron_compile_commands' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = ..."
)
load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")
hedron_compile_commands_setup()
