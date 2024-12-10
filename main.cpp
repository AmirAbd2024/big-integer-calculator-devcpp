#include <bits/stdc++.h> 
#include <string>
#include <sstream>
#include <iostream>
#include <conio.h>


using namespace std; 

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

using namespace patch;


string FixRes(string s)
{
	int l = s.length();
	string tmp = "";
	for(int i=0 ; i<l ; i++)
	{
		if (s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9')
		{
			tmp += s[i];
		}
	}
	return tmp;
}


  
// A function to perform division of large numbers 
string longDivision(string number, long divisor) 
{ 
    // As result can be very large store it in string 
    string ans; 
    
    // Find prefix of number that is larger 
    // than divisor. 
    int idx = 0; 
    long temp = number[idx] - '0'; 
    while (temp < divisor) 
       temp = temp * 10 + (number[++idx] - '0'); 
      
    // Repeatedly divide divisor with temp. After  
    // every division, update temp to include one  
    // more digit. 
    while (number.size() > idx) 
    { 
        // Store result in answer i.e. temp / divisor 
        ans += (temp / divisor) + '0'; 
          
        // Take next digit of number 
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
      
    // If divisor is greater than number 
    if (ans.length() == 0) 
        return "0"; 
      
    // else return ans 
    return ans; 
} 
  
// Driver program to test longDivison() 




////////////////////////////////  Sum

  
// Function for finding sum of larger numbers 
string findSum(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate lenght of both string 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n2 - n1; 
  
    // Initialy take carry zero 
    int carry = 0; 
  
    // Traverse from end of both strings 
    for (int i=n1-1; i>=0; i--) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0') + 
                   (str2[i+diff]-'0') + 
                   carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining digits of str2[] 
    for (int i=n2-n1-1; i>=0; i--) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return FixRes(str); 
} 
  
// Driver code 



//////////////////////////////sum end


///////////////////////////// subtraction

bool isSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
        return true; 
    if (n2 > n1) 
        return false; 
  
    for (int i=0; i<n1; i++) 
    { 
        if (str1[i] < str2[i]) 
            return true; 
        else if (str1[i] > str2[i]) 
            return false; 
    } 
    return false; 
} 
  
// Function for finding difference of larger numbers 
string subtraction(string str1, string str2) 
{ 
    // Before proceeding further, make sure str1 
    // is not smaller 
    if (isSmaller(str1, str2)) { cout << "-"; }
    
    if (str1 == str2) return "0";
    
        int m1 = str1.length(), m2 = str2.length(); 
        
        while(m1>m2)
		{
        	str2 = "0" + str2;
        	m1 = str1.length(), m2 = str2.length(); 
		}
		
		m1 = str1.length(), m2 = str2.length(); 
		while(m1<m2)
		{
        	str1 = "0" + str1;
        	m1 = str1.length(), m2 = str2.length(); 
		}
  //cout << str1 << endl;
  
  if (isSmaller(str1, str2)) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n1 - n2; 
  
    // Initially take carry zero 
    int carry = 0; 
  
    // Traverse from end of both strings 
    for (int i=n2-1; i>=0; i--) 
    { 
        // Do school mathematics, compute difference of 
        // current digits and carry 
        int sub = ((str1[i+diff]-'0') - 
                   (str2[i]-'0') - 
                   carry); 
        if (sub < 0) 
        { 
            sub = sub+10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of str1[] 
    for (int i=n1-n2-1; i>=0; i--) 
    { 
        if (str1[i]=='0' && carry) 
        { 
            str.push_back('9'); 
            continue; 
        } 
        int sub = ((str1[i]-'0') - carry); 
        if (i>0 || sub>0) // remove preceding 0's 
            str.push_back(sub+'0'); 
        carry = 0; 
  
    } 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
  string tmp = "";
  bool allZeroEndInLeft = false;
  
  for(int i=0 ; i<str.length() ; i++)
  {
  	if (!allZeroEndInLeft && str[i] != '0') { allZeroEndInLeft = true; i--; }
	  if (allZeroEndInLeft) { tmp += str[i]; }
  }
  
    return FixRes(tmp); 
    //return str;
} 





/////////////////////////////////// subtraction end


/////////////////////////////// multiple

// Multiplies str1 and str2, and prints result. 
string multiply(string num1, string num2) 
{ 

    int n1 = num1.size(); 
    int n2 = num2.size(); 
    if (n1 == 0 || n2 == 0) 
    return "0"; 
   
    // will keep the result number in vector 
    // in reverse order 
    vector<int> result(n1 + n2, 0); 
   
    // Below two indexes are used to find positions 
    // in result.  
    int i_n1 = 0;  
    int i_n2 = 0;  
       
    // Go from right to left in num1 
    for (int i=n1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
   
        // To shift position to left after every 
        // multiplication of a digit in num2 
        i_n2 = 0;  
           
        // Go from right to left in num2              
        for (int j=n2-1; j>=0; j--) 
        { 
            // Take current digit of second number 
            int n2 = num2[j] - '0'; 
   
            // Multiply with current digit of first number 
            // and add result to previously stored result 
            // at current position.  
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
   
            // Carry for next iteration 
            carry = sum/10; 
   
            // Store result 
            result[i_n1 + i_n2] = sum % 10; 
   
            i_n2++; 
        } 
   
        // store carry in next cell 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
   
        // To shift position to left after every 
        // multiplication of a digit in num1. 
        i_n1++; 
    } 
   
    // ignore '0's from the right 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
   
    // If all were '0's - means either both or 
    // one of num1 or num2 were '0' 
    if (i == -1) 
    return "0"; 
   
    // generate the result string 
    string s = ""; 
       
    while (i >= 0) 
        s += patch::to_string(result[i--]); 
   
    return FixRes(s); 
} 


////////////////////////////// multiple end





/////////////////////////////// pow

// pow str1 and str2, and prints result. 
string power(string num1, string num2) 
{ 

		if (num2=="1") return num1;
		if (num2=="0") return "1";
		if (num1=="0") return "0";
		if (num1=="1") return "1";

    int n1 = num1.size(); 
    int n2 = num1.size(); 
    if (n1 == 0 || n2 == 0) 
    return "0"; 
   
    // will keep the result number in vector 
    // in reverse order 
    vector<int> result(n1 + n2, 0); 
   
    // Below two indexes are used to find positions 
    // in result.  
    int i_n1 = 0;  
    int i_n2 = 0;  
       
    // Go from right to left in num1 
    for (int i=n1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
   
        // To shift position to left after every 
        // multiplication of a digit in num2 
        i_n2 = 0;  
           
        // Go from right to left in num2              
        for (int j=n2-1; j>=0; j--) 
        { 
            // Take current digit of second number 
            int n2 = num1[j] - '0'; 
   
            // Multiply with current digit of first number 
            // and add result to previously stored result 
            // at current position.  
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
   
            // Carry for next iteration 
            carry = sum/10; 
   
            // Store result 
            result[i_n1 + i_n2] = sum % 10; 
   
            i_n2++; 
        } 
   
        // store carry in next cell 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
   
        // To shift position to left after every 
        // multiplication of a digit in num1. 
        i_n1++; 
    } 
   
    // ignore '0's from the right 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
   
    // If all were '0's - means either both or 
    // one of num1 or num2 were '0' 
    if (i == -1) 
    return "0"; 
   
    // generate the result string 
    string s = ""; 
       
    while (i >= 0) 
        s += patch::to_string(result[i--]); 
        
        //cout << subtraction(num2,"2") << endl;
        //return "";
        
   //cout << subtraction(num2,"1") << endl;
   if (num2 == "2") {return s; }
   else { return multiply(num1, power(num1,subtraction(num2,"1"))) ; }
   
   //return s;
    
} 


////////////////////////////// pow end





int main() 
{ 
string op = "";
string str1 = ""; 
string str2 = ""; 
long divisor = 1; 

cout << "Enter operator (+.-.*./.^) : ";
cin >> op;
cout << "Enter number 1 : ";
cin >> str1;
cout << "Enter number 2 : ";

if (op == "/") { cin >> divisor; }
else { cin >> str2; }

if (op=="/")
	{
    cout << longDivision(str1, divisor);
	 }    
	 
	 else if (op=="+")
	{
    cout << findSum(str1, str2); 
	 } 
	 
	 else if (op=="-")
	{
    cout << subtraction(str1, str2) << endl; 
	}
	 
	 else if (op=="*")
	{
       
    if((str1.at(0) == '-' || str2.at(0) == '-') &&  
        (str1.at(0) != '-' || str2.at(0) != '-' )) 
        cout<<"-"; 
   
   
    if(str1.at(0) == '-' && str2.at(0)!='-') 
        { 
            str1 = str1.substr(1); 
        } 
        else if(str1.at(0) != '-' && str2.at(0) == '-') 
        { 
            str2 = str2.substr(1); 
        } 
        else if(str1.at(0) == '-' && str2.at(0) == '-') 
        { 
            str1 = str1.substr(1); 
            str2 = str2.substr(1); 
        } 
    cout << multiply(str1, str2); 

	 } 
	 
	 
	 
	 else if (op=="^")
	{
    cout << power(str1, str2); 
	 } 
	 
	  getch();
	 
    return 0;
} 






