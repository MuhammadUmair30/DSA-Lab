//#include <iostream>
//using namespace std;
//
//int getLength(string str, int i)
//{
//    if (str[i] == '\0')
//        return i;
//
//    return getLength(str, i + 1);
//}
//
//bool isPalindrome(string str, int start, int end)
//{
//    if (start >= end)
//        return true;
//
//    if (str[start] != str[end])
//        return false;
//
//    return isPalindrome(str, start + 1, end - 1);
//}
//
//int main()
//{
//    string str;
//    cin >> str;
//
//    int len = getLength(str, 0);
//
//    if (isPalindrome(str, 0, len - 1))
//        cout << "Palindrome String";
//    else
//        cout << "Not a Palindrome String";
//
//    return 0;
//}