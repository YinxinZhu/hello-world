
//  Created by 朱胤鑫
#include<stdio.h>
#include<stdbool.h>
int zhan[40]={0};
int _index=-1;
bool wrong=false,complex_wrong=false,end=false;
int _pop(void){
        if(_index<=-1)
                complex_wrong=true;
        return zhan[_index--];
}
void _push(int x){
    if(_index<40)
            zhan[++_index]=x;
    else{
            wrong=true;
    }
    return;
}
void _push_count(int x){
    int a,b;
    if((x>=48)&&(x<=57))
                _push(x-'0');
    else   if (x=='=')
                end=true;
    else  if(x!='+'&&x!='-'&&x!='/'&&x!='*'){
                wrong=true;
                end=true;
    }
    switch (x){
            case '+':
                   _push(_pop()+_pop());
                   break;
            case '*':
                    _push(_pop()*_pop());
                    break;
            case '-':
                    a=_pop();
                    b=_pop();
                    _push(b-a);
                    break;
            case '/':
                    a=_pop();
                    b=_pop();
                    _push(b/a);
                    break;
    }
    return;
}
int main(){
        char x;
        for (;!wrong;){
                printf("Enter an RPN expression : ");
                for (;!end;){
                        scanf(" %c",&x);
                        _push_count(x);
                }
                if (complex_wrong){
                    printf("Not enough operands in expression.\n");
                    complex_wrong=false;
                    break;
                }
                if (wrong==false)
                        printf("Value of expression : %d\n",zhan[_index--]);
                end=false;
        }
        return 0;
}

