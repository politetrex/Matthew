#include <cstdio>
unsigned long long _MEMORY_RESOURCE[3];
int main(){
    scanf("%llu",&_MEMORY_RESOURCE[2]);
    while(_MEMORY_RESOURCE[2]--){
        scanf("%llu",&_MEMORY_RESOURCE[0]);
        _MEMORY_RESOURCE[1]=0;
        while(_MEMORY_RESOURCE[0]>1){
            _MEMORY_RESOURCE[1]+=_MEMORY_RESOURCE[0];
            _MEMORY_RESOURCE[0]>>=1;
        }
        printf("%llu\n",_MEMORY_RESOURCE[1]+1);
    }
    return 0;
}