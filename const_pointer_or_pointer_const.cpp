#include <cstdio>
//编程规范：如果函数参数类型是指针且仅作输入用，必须在类型前加const修饰，防止指针在函数体内被意外修改。
//参数类型为char *时不能接受const char *var类型的参数，但参数类型为const char *var时，可以接受char *、const char *类型。即提高了参数接受范围。
//如果函数参数类型是“char *str“ ，则编译会报错。
//函数参数类型为”const char *str“类型才可通过。
//如果指针符号”*“在const左侧：* const，表示常指针，
//如果指针符号在const右侧：const char *var、const node * node_ptr，表示指针指向的量为常量。
void print(const char *str){  //right
//void print(char *str)   false
    printf("%s\n",str);
}

int main(){
    const char *str="hello world";
    print(str);

    return 0;
}

