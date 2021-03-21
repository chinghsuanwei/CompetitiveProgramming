#include <iostream>
#include <string> 
#include <math.h>

using namespace std;

bool check(int num)
{
    while(num = num /10)
    {
        if(num % 10 == 4)
        {
            return false;
        }
    }
    
    return true;
}

void adjust_A(int &A, int &B)
{
    std::size_t found;
    do
    {
        string str = to_string(A);
        found = str.find_first_of("4");
        if( found == std::string::npos ) return;
        //2421 -> 2321
        int mod = pow(10, str.length() - found - 1);
        int diff = mod*4;
        A -= diff;
        B += diff;
        
    } while (found != std::string::npos);
}

void adjust_B(int &A, int &B)
{
    std::size_t found;
    do
    {
        string str = to_string(B);
        found = str.find_first_of("4");
        if( found == std::string::npos ) return;
        //2421 -> 2521
        int mod = pow(10, str.length() - found - 1);
        int diff = mod*4;
        B += diff;
        A -= diff;
        
    } while (found != std::string::npos);
}

int main()
{
	//FILE *input;
	//FILE *output;
	//freopen_s(&input, "A-large.in", "r", stdin);
	//freopen_s(&output, "A-large.out", "w", stdout);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++){
		int N;
		int A, B;
		cin >> N;

		A = B = N / 2;
		if(B % 2) B++;
		
        while (!check(A) && !check(B))
        {
            if (!check(A))
            {
                adjust_A(A, B);
            }

            if (!check(B))
            {
                adjust_B(A, B);
            }
        }
		
		cout << "Case #" << i << ": " << A << " " << B << endl;
	}


}