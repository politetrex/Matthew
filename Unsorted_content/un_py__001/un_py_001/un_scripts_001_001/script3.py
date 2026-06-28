import bcrypt
import hashlib
from typing import Tuple
import time

class SHA256_BCryptHasher:
    """Handles passwords of any length by pre-hashing with SHA-256"""
    
    @staticmethod
    def hash(password: str, rounds: int = 17) -> str:
        """Hash a password of any length"""
        # Convert to bytes
        password_bytes = password.encode('utf-8')
        
        # SHA-256 hash (always 32 bytes)
        sha256_bytes = hashlib.sha256(password_bytes).digest()
        
        # BCrypt hash the SHA-256 output
        bcrypt_hash = bcrypt.hashpw(sha256_bytes, bcrypt.gensalt(rounds=rounds))
        
        # Return as string
        return bcrypt_hash.decode('utf-8')
    
    @staticmethod
    def verify(password: str, stored_hash: str) -> bool:
        """Verify a password against its hash"""
        # Convert to bytes
        password_bytes = password.encode('utf-8')
        
        # SHA-256 hash (same process as during hashing)
        sha256_bytes = hashlib.sha256(password_bytes).digest()
        
        # Verify with BCrypt
        return bcrypt.checkpw(sha256_bytes, stored_hash.encode('utf-8'))

# Test it
hasher = SHA256_BCryptHasher()

# Test with different password lengths
passwords = [
    """#include<iostream>
#include<vector> 
using namespace std;
struct stronghash {
	static const long long MOD1=1000000007,MOD2=1000000009,BASE=91138233;
	vector<long long>pow1,pow2,pref1,pref2;
	stronghash(const string&s) {
		int n=s.size();
		pow1.resize(n+1);
		pow2.resize(n+1);
		pref1.resize(n+1);
		pref2.resize(n+1);
		pow1[0]=pow2[0]=1;
		for(int i=1; i<=n; i++)
			pow1[i]=pow1[i-1]*BASE%MOD1,pow2[i]=pow2[i-1]*BASE%MOD2;
		for(int i=0; i<n; i++)
			pref1[i+1]=(pref1[i]*BASE+s[i])%MOD1,pref2[i+1]=(pref2[i]*BASE+s[i])%MOD2;
	}
	pair<long long,long long>get_hash(int l,int r)const {
		long long h1=(pref1[r]-pref1[l]*pow1[r-l])%MOD1;
		if(h1<0)h1+=MOD1;
		long long h2=(pref2[r]-pref2[l]*pow2[r-l])%MOD2;
		if(h2<0)h2+=MOD2;
		return {h1,h2};
	}
};
int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin>>n;
    string res;
    while(n--){
        string w;cin>>w;
        if (res.empty())res=w;
        else{
            int max_len = min((int)res.size(), (int)w.size());
            stronghash hash_res(res);
            stronghash hash_w(w);
            int overlap=0;
            for (int len=max_len; len>=1;len--)
                if (hash_res.get_hash(res.size()-len,res.size())==hash_w.get_hash(0, len)){
                    overlap=len;break;
                }
            res+=w.substr(overlap);
        }
        
    }
    cout<<res;return 0;
}"""
]

for i in range(1):
    for pwd in passwords:
        # print(f"\nPassword length: {len(pwd.encode('utf-8'))} bytes")
        start = time.perf_counter()
        hash_value = hasher.hash(pwd)
        elapsed = time.perf_counter() - start
        print(f"Hash: {hash_value} \t | Time: {elapsed} \t seconds")