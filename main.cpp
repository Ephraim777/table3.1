#include <iostream>
#include <string>

int naive_search(std::string& source, std::string& find)
{
    int n = source.length();
    int m = find.length();

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (source[i + j] != find[j])
            {
                break;
            }
        }
        if (j == m)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    std::string str1 = "sdaqsdasdhello";
    std::string str2 = "sdh";
    std::cout << naive_search(str1, str2);

    return 0;
}