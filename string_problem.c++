/*

problem statement:-
Encoding Three Strings: Anand was assigned the task of coming up with an encoding mechanism for any given three strings. He has come up with the below plan

STEP ONE: Given any three strings, break each string into 3 parts each,
For Example- If three strings are as below -
input1="John"
input2="Johny"
input3="Janardhan"
"John" should be split into "J","oh","n" as the FRONT, MIDDLE and END parts respectively.
"Johny" should be split into "Jo","h","ny" as the FRONT, MIDDLE and END parts respectively.
"Janardhan" should be split into "Jan","ard","han" as the FRONT, MIDDLE and END parts respectively.
i.e. if the no of characters in the string are in the multiples of 3, then each split part will contain equal no of characters. as seen in the example of "Janardhan".
If the no. of characters in the string are NOT in multiples of 3, then the middle part will get the extra character, as seen in the example of "John".
If the no. of characters in the string are NOT in multiples of 3, and if there are two characters more than multiple of 3, then the FRONT and END parts will get one extra character each, as seen in the example of "Johny"
STEP TWO: Concatenate(join) the FRONT, MIDDLE and END parts of the strings as per the below specified concatenation-rule to form three output strings.
Output1=FRONT part of input1+MIDDLE part of input2+END part of input3
Output2=MIDDLE part of input1+END part of input2+FRONT part of input3
Output3=END part of input1+FRONT part of input2+MIDDLE part of input3
For Example, for the above specified example input strings,
Output1="J"+"h"+"han"="Jhhan"
Output2="oh"+"ny"+"Jan"="ohnyJan"
Output3="n"+"Jo"+"ard"="nJoard"
STEP THREE: Process the resulting output strings based on the output Processing rule.
After the above two steps, we will now have three output strings. Further processing is required only for the third output string as per below rule-"Toggle the case of each character in the string", i.e. in the third output string, all lower-case characters should be made upper-case and vice versa.
For Example, for the above example strings, Output3 is "nJoard", so after applying the toggle rule, Output3 should become "NjOARD".
Final result- The three output strings after applying the above three steps is the final result. i.e. for the above example.
Output1="Jhhan"
Output2="ohnyJan"
Output3="NjOARD"
Anand approaches you to help him write a program that would do the above mentioned processing on any given three strings and generate the resulting three output strings.
The given functions three parameters, input1,input2,input3 represent the three given input strings and return a "Result" object/struct with the three output strings.
*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=3;
    string a[n],arr[9];
    for(int i=0;i<n;i++){cin>>a[i];}
    int i=0,k=0;
    while(i<n){
        string s=a[i];
        i++;
        int l=s.size();
        int d=l/3;
        int r=l%3;
        int f=0,m=0,e=0;
        if(l%3==0){f=d;m=d;e=d;}
        else if(r%2==0){f=d+1;m=d;e=d+1;}
        else{f=d;m=d+1;e=d;}
        arr[k]=s.substr(0,f);k++;
        arr[k]=s.substr(f,m);k++;
        arr[k]=s.substr(m+f,e);k++;
    }
    string s1="",s2="",s3="";
    s1.append(arr[0]);s1.append(arr[4]);s1.append(arr[8]);
    s2.append(arr[1]);s2.append(arr[5]);s2.append(arr[6]);
    s3.append(arr[2]);s3.append(arr[3]);s3.append(arr[7]);
    for(int j=0;j<s3.size();j++){
        if(isupper(s3[j])){s3[j]=tolower(s3[j]);}
        else{s3[j]=toupper(s3[j]);}
    }
    cout<<endl<<s1<<"\n"<<s2<<"\n"<<s3;
     return 0;
}

//input1="John"input2="Johny"input3="Janardhan"
//Output1="Jhhan"Output2="ohnyJan"Output3="NjOARD"
  


