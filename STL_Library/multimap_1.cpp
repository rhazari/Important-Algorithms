#include <iostream>
#include <cstring>
#include <utility>
#include <map>

#define NPRIMES 26

using namespace std;

// alphabet in the order of frequency
char freq[] =  {'e','a','r','i','o','t','n','s','l','c',
                'u','d','p','m','h','g','b','f','y','w',
                'k','v','x','z','j','q'};

// sample anagrams
char *dict[] = {"acre", "care", "race", "rade", 
                "sender", "enders", "resend", "pender",
                "veto", "vote", "vet" };

int isPrime(int num)
{
    int k;
    for(k = 2; k <= num/2; k++)
    {
        if(num%k == 0)
        {
            return 0;
        }
    }
    return 1;
}

void getPrimes(int *array)
{
    int k, count = 0 ;
    for(k = 2; k<200; k++)
    {
        if(isPrime(k))
        {    
            array[count++] = k;
        }
        if(count >= NPRIMES)
        {
            break;
        }
    }
}

void setmap(multimap<int, char*> &mmap, int *array)
{
    int size_dict = sizeof(dict)/sizeof(dict[1]);
    int k, j, length, p, mul;
    for( k = 0; k<size_dict; k++)
    {
        length = strlen(dict[k]);
        p = 0;
        mul = 1;
        for(j = 0; j<length; j++)
        {
            while(dict[k][j] != freq[p])
            {
                ++p;
            }
            
            mul = mul*array[p];
            p = 0;        
        }
        //cout<<mul<<"\n";
        //cout<<dict[k]<<"\n";
        mmap.insert(make_pair(mul,dict[k]));
    }
}


int main()
{
    int j;
    int *primes = new int[NPRIMES];
    getPrimes(primes);
    
    cout<<"First 26 prime numbers\n";
    for(j = 0; j < NPRIMES; j++)
    {
        cout<<primes[j]<<" ";
    }
    cout<<"\n";    

    multimap<int, char* > anagram;
    setmap(anagram, primes);

    multimap<int,char*> :: iterator itr;
    cout<<"Example of Multimap in work\n";
    for(itr = anagram.begin(); itr != anagram.end(); itr++)
    {
        cout<<itr->first<<"=>"<<itr->second<<"\n";
    }
    
    cout<<"\n";
    return 0;
}
