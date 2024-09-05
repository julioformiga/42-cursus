#include <gtest/gtest.h>

TEST(MiniShellTest, ExampleTest) {
    EXPECT_EQ(1, 1);
}

TEST(MiniShellTest, EchoCommandTest) {
    std::string command = "minishell";
    std::string input = "ls\nexit\n";
    std::string expected_output = "ls\n";

    FILE* pipe = popen(command.c_str(), "r+");
    if (!pipe) {
        FAIL() << "Failed to open pipe";
    }

    fwrite(input.c_str(), sizeof(char), input.size(), pipe);
    fflush(pipe);

    std::ostringstream output_stream;
    FILE* output_pipe = popen((command + " 2>&1").c_str(), "r");
    if (!output_pipe) {
        FAIL() << "Failed to open output pipe";
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), output_pipe) != nullptr) {
        output_stream << buffer;
        if (output_stream.str().find("exit") != std::string::npos) {
            break;
        }
    }
    pclose(output_pipe);

    EXPECT_EQ(output_stream.str(), expected_output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
