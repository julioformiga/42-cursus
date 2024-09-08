#include <gtest/gtest.h>
#include <iostream>

using namespace std;

TEST(minishell, test1) {
    cout << "Test 1" << endl;
    ASSERT_TRUE(true);
}

TEST(minishell, no_memory_leaks) {
    const char* command = "echo 'exi' | valgrind --leak-check=full --show-leak-kinds=all --suppressions=../readline.supp --error-exitcode=1 ./minishell";
    int result = system(command);
    ASSERT_EQ(result, 0) << "Memory leak detected or error occurred";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
