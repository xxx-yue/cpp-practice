#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include <limits.h>
#include <stdlib.h>
#include<math.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NOVEL_FILE "我只喜欢你的人设[娱乐圈].txt"
const char* novel_names[17] = {
    "我只喜欢你的人设1.txt",
    "我只喜欢你的人设2.txt",
    "我只喜欢你的人设3.txt",
    "我只喜欢你的人设4.txt",
    "我只喜欢你的人设5.txt",
    "我只喜欢你的人设6.txt",
    "我只喜欢你的人设7.txt",
    "我只喜欢你的人设8.txt",
    "我只喜欢你的人设9.txt",
    "我只喜欢你的人设10.txt",
    "我只喜欢你的人设11.txt",
    "我只喜欢你的人设12.txt",
    "我只喜欢你的人设13.txt",
    "我只喜欢你的人设14.txt",
    "我只喜欢你的人设15.txt",
    "我只喜欢你的人设16.txt",
    "我只喜欢你的人设17.txt"
};


char* read_novel_from_project() 
{
  
    FILE* fp = fopen(NOVEL_FILE, "r");
    if (fp == NULL) {
        printf(" 找不到项目里的【%s】！请确认文件在项目根目录\n", NOVEL_FILE);
        return NULL;
    }

   
    fseek(fp, 0, SEEK_END); 
    long file_size = ftell(fp); 
    fseek(fp, 0, SEEK_SET);  

    
    char* content = (char*)malloc(file_size + 1);  
    if (content == NULL) {
        printf(" 内存不足！\n");
        fclose(fp);
        return NULL;
    }

   
    fread(content, 1, file_size, fp);
    content[file_size] = '\0';  
    fclose(fp);

    return content;
}

int main() {
    
    system("chcp 936 > nul");

   
    char* novel_content = read_novel_from_project();
    if (novel_content == NULL) {
        system("pause");
        return 1;
    }

   
    char* user = getenv("USERPROFILE");
    if (user == NULL) {
        printf(" 获取桌面路径失败！\n");
        free(novel_content);
        system("pause");
        return 1;
    }
    char desktop_path[256];
    sprintf(desktop_path, "%s\\Desktop\\", user);

    
    int success = 0;
    for (int i = 0; i < 17; i++) {
        char file_path[300];
        sprintf(file_path, "%s%s", desktop_path, novel_names[i]);

        
        FILE* fp = fopen(file_path, "w");
        if (fp != NULL) {
            fputs(novel_content, fp);
            fclose(fp);
            success++;
        }
        else {
            printf(" 生成失败：%s（权限不足）\n", novel_names[i]);
        }
    }

   
    free(novel_content);
    printf("恭喜你中大奖啦李依敏！\n", success);
    system("pause > nul");
    return 0;
}