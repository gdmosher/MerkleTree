/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 10, 2014, 6:49 PM
 * Testing something like a hashcash algorithm
 * Sample output
 *      The initial random number = 867605078
 *      The base message = What a difference a day makes!
 *      The total time take = 5 (secs)
 *      The number of zeroes = 5
 *      The hex output = 00000273f4e5e9e2c510995a0b1116cdaf6d4f5f
 *              0 zeroes occured 915586 times
 *              1 zeroes occured 57248 times
 *              2 zeroes occured 3557 times
 *              3 zeroes occured 212 times
 *              4 zeroes occured 22 times
 *              5 zeroes occured 1 times
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <ctime>
#include <sstream>
using namespace std;

//Sha1 algorithm copied from somewhere
#include "sha1.h"
using namespace sha1;

//Function Prototypes
int count0(char [],int);
void prntRes(int [],int);
string sha1HexString(string s) {
	char cMsg[100];
	int size;
	const int HXSIZE = 41;
	char hex[HXSIZE];
	unsigned char code[20];

	//Convert to a character message
	strcpy_s(cMsg, s.c_str());
	size = sizeof(cMsg) - 1;
	//utilize the sha1 function
	calc(cMsg, size, code);
	toHexString(code, hex);
	return hex;
}

//Execution Begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Choose a random number and declare the hex for sha1
    int randNum=rand();
    const int HXSIZE=41;
    char hex[HXSIZE];;
	unsigned char code[20];
/*
	cout << "The initial random number = " << randNum << endl;
    //Create a message
    string msg="What a difference a day makes!";
    cout<<"The base message = "<<msg<<endl;
*/
	//Setup the number of loops and loop variables
    int endLoop=3,freq[HXSIZE]={},cntZero=0;
    //Record the start time
    int strTime=time(0);
    //Loop until you have reached the number of zeroes desired
 /*
	do{
        //Create a concatenation of the two by first converting the random
        //number to a string
        ostringstream convert;   // stream used for the conversion
        convert << randNum++;      // insert the textual representation of 'Number' in the characters in the stream
        string strRnd = convert.str();
        string newMsg=msg+strRnd;
        //cout<<newMsg<<endl;
        //Convert to a character message
        char cMsg[100];
        strcpy_s(cMsg, newMsg.c_str());
        int size=sizeof(cMsg)-1;
        //utilize the sha1 function
        calc(cMsg, size, code);
        toHexString(code, hex);
        cntZero=count0(hex,endLoop+1);
        freq[cntZero]++;
    }while(cntZero<endLoop);
	//Take the time it took
    int endTime=time(0);
    //Output the result
    cout<<"The total time take = "<<endTime-strTime<<" (secs)"<<endl;
    cout<<"The number of zeroes = "<<cntZero<<endl;
    cout<<"The hex output = "<<hex<<endl;
    prntRes(freq,cntZero);
*/
	/**************************************************************/
	char cMsg[100];
	int size;
	string L1 = "\
		Then out spake brave Horatius,\n\
		The Captain of the Gate : ";
	string L2 = "\n\
		To every man upon this earth\n\
		Death cometh soon or late.";
	string L3 = "\n\
		And how can man die better\n\
		Than facing fearful odds,\n\
		and";							//this line doesn't belong in the quote, but it's in my tests so I leave it for now
	string L4 = "\n\
		For the ashes of his fathers,\n\
		And the temples of his Gods.";
	cout << L1 << L2 << L3 << L4 << endl;
	string hash00, hash01, hash10, hash11, hash0, hash1, hashTop;
	//L1
	hash00 = sha1HexString(L1);
	cout << "hash00\t" << hash00 << endl;
	//L2
	hash01 = sha1HexString(L2);
	cout << "hash01\t" << hash01 << endl;
	//L3
	hash10 = sha1HexString(L3);
	cout << "hash10\t" << hash10 << endl;
	//L4
	hash11 = sha1HexString(L4);
	cout << "hash11\t" << hash11 << endl;
	//hash0
	hash0 = sha1HexString(hash00 + hash01);
	cout << "hash0\t" << hash0 << endl;
	//hash1
	hash1 = sha1HexString(hash10 + hash11);
	cout << "hash1\t" << hash1 << endl;
	//hashTop
	hashTop = sha1HexString(hash0 + hash1);
	cout << "hashTop\t" << hashTop << endl;
	cout << endl;
	cout << "Results are pasted to .cpp file, Change L1, re-run," << endl;
	cout << "compare results also pasted to.cpp file." << endl;
	cout << "hash00, hash0, and hashTop changed as expected." << endl;
	cout << "Run and paste comparisons for changes in L2, L3, and L4 also." << endl;
	cout << endl;
	cout << "Please look in the end of main.cpp for the results of all four tests." << endl;
	cout << endl;

	/**************************************************************/
	//Exit stage right

	system("Pause");
    return 0;
}

void prntRes(int freq[],int n){
    //Output the frequency for each occurence
    for(int i=0;i<=n;i++){
        cout<<i<<" zeroes occured "<<freq[i]<<" times"<<endl;
    }
}

int count0(char str[],int n){
    int cnt=-1;
    do{
        cnt++;
    }while(str[cnt]=='0');
    return cnt;
}

/*
Then out spake brave Horatius,
The Captain of the Gate :
To every man upon this earth
Death cometh soon or late.
And how can man die better
Than facing fearful odds,
and
For the ashes of his fathers,
And the temples of his Gods.
hash00  13b8260ef27b7682f88ae1b2c54d0ea7e6d45927
hash01  ed07d41fbad8d4e01ec893de449bea5c5589a5b6
hash10  6dbbaefbb2f989da30b22dd255ade35dd0107a9e
hash11  23595367095aae85668b47386c4b63a0b4731346
hash0   5063fd126ab6c91ad9e2800ae214f81bf57b6bf3
hash1   7d5dc2b98487cb921dd7ce8ac87749b66ee2df18
hashTop 41a81c9cce800569722eacf694405c6c2097fa85
Press any key to continue . . .

L1 is changed
Then out spake brave Horatius,
The Captain of the Gate :
To every man upon this earth
Death cometh soon or late.
And how can man die better
Than facing fearful odds,
and
For the ashes of his fathers,
And the temples of his Gods.
hash00  449931f3cc1a4b848155634a903a817e08f4e78b
hash01  ed07d41fbad8d4e01ec893de449bea5c5589a5b6
hash10  6dbbaefbb2f989da30b22dd255ade35dd0107a9e
hash11  23595367095aae85668b47386c4b63a0b4731346
hash0   b22c13557c333db5d6eefc830a2a77092983b3c7
hash1   7d5dc2b98487cb921dd7ce8ac87749b66ee2df18
hashTop 26fc29c92f49b7f130aa2cf520bfafde1266ecf0
Results are pasted to .cpp file, Change L1, re-run, compare results also pasted to .cpp file.
Press any key to continue . . .

L2 is changed
Then out spake brave Horatius,
The Captain of the Gate :
To every man upon this earth
Death cometh soon or late.
And how can man die better
Than facing fearful odds,
and
For the ashes of his fathers,
And the temples of his Gods.
hash00  13b8260ef27b7682f88ae1b2c54d0ea7e6d45927
hash01  27902e4fd9f5683e1a0c0daa02835745fd0ce1c4
hash10  6dbbaefbb2f989da30b22dd255ade35dd0107a9e
hash11  23595367095aae85668b47386c4b63a0b4731346
hash0   7cec2cfbe7b550a46444990ca8c3d769cf3aafed
hash1   7d5dc2b98487cb921dd7ce8ac87749b66ee2df18
hashTop 73ce980d800744bc8feb71b3d3df9906fe124b23
Results are pasted to .cpp file, Change L1, re-run,
compare results also pasted to.cpp file.
hash00, hash0, and hashTop changed as expected.
Run and paste comparisons for changes in L2, L3, and L4 also.
Press any key to continue . . .

L3 is changed
Then out spake brave Horatius,
The Captain of the Gate :
To every man upon this earth
Death cometh soon or late.
And how can man die better
Than facing fearful odds,
and
For the ashes of his fathers,
And the temples of his Gods.
hash00  13b8260ef27b7682f88ae1b2c54d0ea7e6d45927
hash01  ed07d41fbad8d4e01ec893de449bea5c5589a5b6
hash10  26f60dc0a3e5b7b0d9adb3c701a89aed9b908b30
hash11  23595367095aae85668b47386c4b63a0b4731346
hash0   5063fd126ab6c91ad9e2800ae214f81bf57b6bf3
hash1   ceb7309366ba0f53951000bc1a6344b56a3778b3
hashTop 7537a24453016774c97d5a1410a082d9b65162dc
Results are pasted to .cpp file, Change L1, re-run,
compare results also pasted to.cpp file.
hash00, hash0, and hashTop changed as expected.
Run and paste comparisons for changes in L2, L3, and L4 also.
Press any key to continue . . .

L4 is changed
Then out spake brave Horatius,
The Captain of the Gate :
To every man upon this earth
Death cometh soon or late.
And how can man die better
Than facing fearful odds,
and
For the ashes of his fathers,
And the temples of his Gods.
hash00  13b8260ef27b7682f88ae1b2c54d0ea7e6d45927
hash01  ed07d41fbad8d4e01ec893de449bea5c5589a5b6
hash10  6dbbaefbb2f989da30b22dd255ade35dd0107a9e
hash11  bc26383ea3250747dbd0d89b2b3c0a81989d441e
hash0   5063fd126ab6c91ad9e2800ae214f81bf57b6bf3
hash1   946b648d748a0d42772abfb0c42dcfd9da649491
hashTop a671686d30b298aca68acb55af31d449521d6a63
Results are pasted to .cpp file, Change L1, re-run,
compare results also pasted to.cpp file.
hash00, hash0, and hashTop changed as expected.
Run and paste comparisons for changes in L2, L3, and L4 also.
Press any key to continue . . .
*/