#include <bits/stdc++.h>

using namespace std;

int convert(string s){
    int x;
    stringstream ss;
    ss << std::hex << s;
    ss >> x;
    return x;
}

int main(){
    //cout << hex << convert("fff");
    string src = "0a 63 7c 03",
    dest = "5f 67 5a c8",
    sp = "3b c2",
    dp = "7f 19",
    len = "00 1c",
    checksum = "ac d8",
    data = "41:00:ba:90:00:8a:68:41:00:00:00:00:00:10:00:00:f2:ff:00:00";

    string inp = src + dest + "00" +
    return 0;
}


