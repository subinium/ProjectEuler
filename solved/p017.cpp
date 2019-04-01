#include <stdio.h>
// one two three four five six seven eight nine
// 3 3 5 4 4 3 5 5 4 = 36
// ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen
// 3 6 6 8 8 7 7 9 8 8 = 70
// twenty thirty forty fifty sixty seventy eighty ninety
// 6 6 5 5 5 7 6 6 = 46

int main(){
    int tot = 0;
    tot += 36 * 9 + 70 + 460;
    tot *= 10; // 1~99 * 10
    tot += 3 * 99 * 9; // and
    tot += 7*900; // hundred
    tot += 36 * 100; //front hundred 
    tot += 3 + 8; // one thousand
    printf("%d",tot);
}

