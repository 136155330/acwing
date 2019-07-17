#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
struct Filetools{
    char path[105];///用户输入的文件路径
    char dirpath[105];///用户输入的文件夹路径
    void add_file(){///添加文件路径
        cout << "please cin the file: ";
        cin >> path;
    }
    void creat_file(){///创建文件
        add_file();
        open(path, O_CREAT, 0777);
        return ;
    }
    void write_file(){///对文件写入内容
        add_file();
        getchar();
        cout << "please cin you things: ";
        char a[1005];
        memset(a, 0, sizeof(a));
        cin.getline(a, 505);///采用cin.getline，可以一次读取一行
        int fp = open(path, O_RDWR);
        write(fp, a, strlen(a));///写入fp文件，一次写入一行
        close(fp);
    }
    void read_file(){
        add_file();
        cout << "the read the file is running\n";
        char a[1005];
        memset(a, 0, sizeof(a));
        FILE *fp;
        fp = fopen(path, "r");
        while(fgets(a, 1000, fp) != NULL){///每次读取一行，如果不到最后一行就一直读取
            cout << a;///输出读取的结果
        }
        fclose(fp);///关闭读取的文件
    }
    void copy(){
        add_file();
        cout << "please cin the other file: ";
        char paths[1005];
        memset(paths, 0, sizeof(paths));
        cin >> paths;
        FILE *fp;
        fp = fopen(path, "r");
        int pid = fork();///创建一个子进程来进行对复制文件的写入，这样的话，就不会让freopen的读出效果影响主程序
        if(pid == 0){
        freopen(paths, "w", stdout);///采用freopen的读出方式
        char a[1005];
        memset(a, 0, sizeof(a));
        while(fgets(a, 1000, fp) != NULL){
            cout << a;///输出文件中的内容到另一个文件来实现复制
        }
        fclose(fp);
        return ;
        }
    }
    void my_File_chmod(){
        add_file();
        int fp = open(path, O_RDWR);
        cout << "please cin the mode, such as the list\n";
        cout << "1: S_IRWXU\n";
        cout << "2: S_IRUSR(S_IREAD)\n";
        cout << "3: S_IWUSR(S_IWRITE)\n";
        cout << "4: S_IXUSR(S_IEXEC)\n";
        cout << "cin the num as list :";
        int aa;
        cin >> aa;///选择序号来更改权限
        if(aa == 1)
            fchmod(fp, S_IRWXU);
        if(aa == 2)
            fchmod(fp, S_IRUSR);
        if(aa == 3)
            fchmod(fp, S_IWUSR);
        if(aa == 4)
            fchmod(fp, S_IXUSR);
    }
    void my_ls_file_name(){
        add_file();
        char a[105] = "ls -l ";///采用控制台的方式来进行文件夹目录下的文件的读取
        /**
         * 以下的复制char数组的方法，是因为system(char *)
         * 所以将命令拷贝到一个char数组里，就可以实现system的命令
         * **/
        int len = strlen(a);
        int len1 = strlen(path);
        for(int i = len; i < len + len1; i ++){
            a[i] = path[i - len];
        }
        int pid = fork();///fork一个子进程可以使得父进程不结束
        if(pid == 0){
            system(a);
            return ;
        }
        wait(0);
    }
    void add_dir(){///输入文件夹路径
        cout << "please cin the dirname :";
        cin >> dirpath;
    }
    void creat_dir(){
        char a[205] = "mkdir ";///使用mkdir语句来生成文件夹
        int len = strlen(a);
        add_dir();
        int len1 = strlen(dirpath);
        for(int i = len; i < len + len1; i ++){
            a[i] = dirpath[i - len]; 
        }
        int pid = fork();
        if(pid == 0){
            system(a);
            return ;
        }
        wait(0);
    }
    void ls_dir(){
        char a[205] = "ls ";///使用ls语句来读取文件夹下的文件
        int len = strlen(a);
        int len1 = strlen(dirpath);
        for(int i = len; i < len + len1; i ++){
            a[i] = dirpath[i - len]; 
        }
        int pid = fork();
        if(pid == 0){
            system(a);
            return ;
        }
        wait(0);
    }
    void del_dir(){
        add_dir();
        char a[205] = "rm -rf ";///rm -rf语句来删除文件夹
        int len = strlen(a);
        int len1 = strlen(dirpath);
        for(int i = len; i < len + len1; i ++){
            a[i] = dirpath[i - len]; 
        }
        int pid = fork();
        if(pid == 0){
            system(a);
            return ;
        }
        wait(0);
    }
    void cd_dir(){
        add_dir();
    }
}F;
void view(){///菜单
    cout << "1. 创建新文件\n";
    cout << "2. 写文件\n";
    cout << "3. 读文件\n";
    cout << "4. 复制文件\n";
    cout << "5. 修改文件权限\n";
    cout << "6. 查看文件权限\n";
    cout << "7. 创建目录\n";
    cout << "8. 查看目录\n";
    cout << "9. 删除目录\n";
    cout << "10. 切换当前目录\n";
    cout << "0.退出\n";
}
int main(){
    while(1){
        view();
        int num;
        cin >> num;
        if(num == 0){
            break;
        }
        if(num == 1){
            F.creat_file();
        }
        if(num == 2){
            F.write_file();
        }
        if(num == 3){
            F.read_file();
        }
        if(num == 4){
            F.copy();
        }
        if(num == 5){
            F.my_File_chmod();
        }
        if(num == 6){
            F.my_ls_file_name();
        }
        if(num == 7){
            F.creat_dir();
        }
        if(num == 8){
            F.ls_dir();
        }
        if(num == 9){
            F.del_dir();
        }
        if(num == 10){
            F.cd_dir();
        }
    }
    return 0;
}