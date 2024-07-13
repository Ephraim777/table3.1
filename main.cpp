#include <iostream>
#include <cmath>
int real_string_hash(std::string& str, int k)
{
    int n = 1000;
    int p = 13;
    uint64_t member = 0;
    uint64_t current_p = 1;
    for(int i = 0; i < k; i++)
    {
        if(i == 0)
        {
        member += static_cast< uint64_t>(str[i]);
        }
        else
        {
            current_p *= p;
            member += static_cast< uint64_t>(str[i]) * current_p;
        }

    }
    return static_cast<int>(member%n);
}

int Robin_Carp(std::string &source, std::string &find)
{
 int k = static_cast<int>(find.length());
 int hash_find = real_string_hash(find,k);
 int hash_source = 0;

 for( int i =0; i < source.length(); i++)
 {
   if ( i == 0)
   {
       hash_source = real_string_hash(source,k);
   }
   else
   {
    hash_source -=source[i-1];
    hash_source +=source[i+k-1];
   }
     if (hash_source == hash_find)
     {
         bool found = true;
         for (int j = 0; j < k; j++)
         {
             if (source[i + j] != find[j])
             {
                 found = false;
                 break;
             }
         }
         if (found)
         {
             return i;
         }
     }

 }
 return -1;
}

int main()
{
    std::string str1 = "sdaqsdasdhello";
    std::string str2 = "daq";
    std::cout << Robin_Carp(str1, str2);

    return 0;
}
