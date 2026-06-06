#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50
#define MAX_MAJOR_LEN 50
#define NUM_SUBJECTS 5

typedef struct {
    char id[15];          // 学号
    char name[MAX_NAME_LEN];
    char major[MAX_MAJOR_LEN];
    float scores[NUM_SUBJECTS];  // 改为浮点数
    float total;          // 总分
    float average;        // 平均分
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

const char* subjects[NUM_SUBJECTS] = { "数学", "英语", "物理", "化学", "计算机" };

// 函数声明
void loadStudents();
void saveStudents();
void appendToFile(Student s);
void addStudent();
void deleteStudent();
void modifyStudent();
void searchStudents();
void statistics();
void sortStudents();
void displayAll();
void printHeader();
void printStudent(Student s);
void clearInputBuffer();
void printWelcome();
void printMainMenu();

int main() {
    loadStudents();  // 启动时加载文件数据

    int choice;
    printWelcome();

    do {
        printMainMenu();
        printf("请选择操作 (1-8): ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("\n\033[1;31m错误：请输入有效数字！\033[0m\n");
            continue;
        }

        switch (choice) {
        case 1: displayAll(); break;
        case 2: addStudent(); break;
        case 3: deleteStudent(); break;
        case 4: modifyStudent(); break;
        case 5: searchStudents(); break;
        case 6: statistics(); break;
        case 7: sortStudents(); break;
        case 8:
            saveStudents();
            printf("\n\033[1;32m数据已保存，感谢使用！\033[0m\n");
            exit(0);
        default:
            printf("\n\033[1;31m无效选择，请重新输入！\033[0m\n");
        }
        printf("\n按回车键继续...");
        clearInputBuffer();
        getchar();
    } while (1);

    return 0;
}

void printWelcome() {
    printf("\n\033[1;35m============================================\033[0m\n");
    printf("\033[1;35m     欢迎使用学生成绩管理系统      \033[0m\n");
    printf("\033[1;35m============================================\033[0m\n\n");
}

void printMainMenu() {
    //system("cls || clear");  // 清屏
    printf("\n\033[1;36m============= 学生成绩管理系统 =============\033[0m\n");
    printf("\033[1;33m1. 显示所有学生信息\033[0m\n");
    printf("\033[1;33m2. 添加学生记录\033[0m\n");
    printf("\033[1;33m3. 删除学生记录\033[0m\n");
    printf("\033[1;33m4. 修改学生记录\033[0m\n");
    printf("\033[1;33m5. 查询学生记录\033[0m\n");
    printf("\033[1;33m6. 统计功能\033[0m\n");
    printf("\033[1;33m7. 排序功能\033[0m\n");
    printf("\033[1;31m8. 退出系统\033[0m\n");
    printf("\033[1;36m===========================================\033[0m\n");
}

void loadStudents() {
    FILE* file = fopen("学生信息.txt", "r");
    if (file == NULL) {
        printf("文件打开失败，将创建新文件\n");
        return;
    }

    studentCount = 0;
    // 修改为适应新格式的读取
    while (fscanf(file, "%s %s %s", students[studentCount].id,
        students[studentCount].name,
        students[studentCount].major) == 3) {

        // 读取5门课程成绩
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            fscanf(file, "%f", &students[studentCount].scores[i]);
        }

        // 读取总分和平均分
        fscanf(file, "%f", &students[studentCount].total);
        fscanf(file, "%f", &students[studentCount].average);

        studentCount++;
    }
    fclose(file);
}

void saveStudents() {
    FILE* file = fopen("学生信息.txt", "w");
    if (file == NULL) {
        printf("\033[1;31m文件保存失败！\033[0m\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%s %s %s", students[i].id, students[i].name, students[i].major);

        // 写入5门课程成绩
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            fprintf(file, " %.1f", students[i].scores[j]);
        }

        // 写入总分和平均分
        fprintf(file, " %.1f %.1f\n", students[i].total, students[i].average);
    }
    fclose(file);
}

void appendToFile(Student s) {
    FILE* file = fopen("学生信息.txt", "a");
    if (file == NULL) {
        printf("\033[1;31m文件追加失败！\033[0m\n");
        return;
    }

    fprintf(file, "%s %s %s", s.id, s.name, s.major);
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        fprintf(file, " %.1f", s.scores[j]);
    }
    fprintf(file, " %.1f %.1f\n", s.total, s.average);
    fclose(file);
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("\n\033[1;31m学生数量已达上限！\033[0m\n");
        return;
    }

    Student newStudent;
    printf("\n\033[1;36m----- 添加新学生 -----\033[0m\n");

    printf("请输入学号: ");
    scanf("%s", newStudent.id);

    // 检查学号是否重复
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, newStudent.id) == 0) {
            printf("\n\033[1;31m学号已存在！\033[0m\n");
            return;
        }
    }

    printf("请输入姓名: ");
    scanf("%s", newStudent.name);
    printf("请输入专业: ");
    scanf("%s", newStudent.major);

    printf("\n\033[1;33m请输入5门课程成绩:\033[0m\n");
    newStudent.total = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("%s: ", subjects[i]);
        scanf("%f", &newStudent.scores[i]);  // 改为%f
        newStudent.total += newStudent.scores[i];
    }
    newStudent.average = newStudent.total / NUM_SUBJECTS;

    students[studentCount] = newStudent;
    studentCount++;
    appendToFile(newStudent);

    printf("\n\033[1;32m学生添加成功！\033[0m\n");
}

void deleteStudent() {
    char id[15];
    printf("\n\033[1;36m----- 删除学生 -----\033[0m\n");
    printf("请输入要删除的学生学号: ");
    scanf("%s", id);

    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, id) == 0) {
            found = 1;
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            saveStudents();
            printf("\n\033[1;32m学生删除成功！\033[0m\n");
            break;
        }
    }

    if (!found) {
        printf("\n\033[1;31m未找到该学生！\033[0m\n");
    }
}
void modifyStudent() {
    char id[15];
    printf("\n\033[1;36m----- 修改学生信息 -----\033[0m\n");
    printf("请输入要修改的学生学号: ");
    scanf("%s", id);

    int found = -1;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, id) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("\n\033[1;31m未找到该学生！\033[0m\n");
        return;
    }

    printf("\n当前信息:\n");
    printHeader();
    printStudent(students[found]);

    int choice;
    do {
        printf("\n\033[1;36m请选择要修改的项目:\033[0m\n");
        printf("1. 学号\n");
        printf("2. 姓名\n");
        printf("3. 专业\n");
        printf("4. 课程成绩\n");
        printf("5. 完成修改\n");
        printf("请选择 (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            char newId[15];
            printf("请输入新学号: ");
            scanf("%s", newId);

            // 检查学号是否重复
            int duplicate = 0;
            for (int i = 0; i < studentCount; i++) {
                if (i != found && strcmp(students[i].id, newId) == 0) {
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate) {
                printf("\033[1;31m学号已存在！\033[0m\n");
            }
            else {
                strcpy(students[found].id, newId);
                printf("\033[1;32m学号修改成功！\033[0m\n");
            }
            break;
        }
        case 2: {
            printf("请输入新姓名: ");
            scanf("%s", students[found].name);
            printf("\033[1;32m姓名修改成功！\033[0m\n");
            break;
        }
        case 3: {
            printf("请输入新专业: ");
            scanf("%s", students[found].major);
            printf("\033[1;32m专业修改成功！\033[0m\n");
            break;
        }
        case 4: {
            printf("\n\033[1;33m请选择要修改的课程:\033[0m\n");
            for (int i = 0; i < NUM_SUBJECTS; i++) {
                printf("%d. %s\n", i + 1, subjects[i]);
            }
            printf("请选择课程编号 (1-%d): ", NUM_SUBJECTS);
            int course;
            scanf("%d", &course);

            if (course < 1 || course > NUM_SUBJECTS) {
                printf("\033[1;31m无效的课程编号！\033[0m\n");
            }
            else {
                printf("请输入新的%s成绩: ", subjects[course - 1]);
                scanf("%f", &students[found].scores[course - 1]);

                // 重新计算总分和平均分
                students[found].total = 0;
                for (int i = 0; i < NUM_SUBJECTS; i++) {
                    students[found].total += students[found].scores[i];
                }
                students[found].average = students[found].total / NUM_SUBJECTS;

                printf("\033[1;32m%s成绩修改成功！\033[0m\n", subjects[course - 1]);
            }
            break;
        }
        case 5:
            saveStudents();  // 保存修改
            printf("\033[1;32m学生信息已更新并保存！\033[0m\n");
            return;
        default:
            printf("\033[1;31m无效选择，请重新输入！\033[0m\n");
        }
    } while (1);
}

void searchStudents() {
    int choice;
    printf("\n\033[1;36m----- 学生查询 -----\033[0m\n");
    printf("1. 按学号查询\n");
    printf("2. 按姓名查询\n");
    printf("3. 按课程查询\n");
    printf("4. 按成绩范围查询\n");
    printf("请选择查询方式 (1-4): ");
    scanf("%d", &choice);

    int found = 0;

    switch (choice) {
    case 1: { // 按学号查询
        char id[15];
        printf("请输入学号: ");
        scanf("%s", id);

        for (int i = 0; i < studentCount; i++) {
            if (strcmp(students[i].id, id) == 0) {
                printHeader();
                printStudent(students[i]);
                found = 1;
                break;
            }
        }
        break;
    }
    case 2: { // 按姓名查询
        char name[MAX_NAME_LEN];
        printf("请输入姓名: ");
        scanf("%s", name);

        printHeader();
        for (int i = 0; i < studentCount; i++) {
            if (strstr(students[i].name, name) != NULL) {
                printStudent(students[i]);
                found = 1;
            }
        }
        break;
    }
    case 3: { // 按课程查询
        int course;
        printf("\n请选择课程:\n");
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            printf("%d. %s\n", i + 1, subjects[i]);
        }
        printf("请选择课程编号 (1-%d): ", NUM_SUBJECTS);
        scanf("%d", &course);

        if (course < 1 || course > NUM_SUBJECTS) {
            printf("\033[1;31m无效的课程编号！\033[0m\n");
            return;
        }

        printHeader();
        for (int i = 0; i < studentCount; i++) {
            printStudent(students[i]);
        }
        found = studentCount > 0;
        break;
    }
    case 4: { // 按成绩范围查询
        float min, max;
        printf("请输入最低分: ");
        scanf("%f", &min);
        printf("请输入最高分: ");
        scanf("%f", &max);

        if (min > max) {
            printf("\033[1;31m分数范围无效！\033[0m\n");
            return;
        }

        printHeader();
        for (int i = 0; i < studentCount; i++) {
            for (int j = 0; j < NUM_SUBJECTS; j++) {
                if (students[i].scores[j] >= min && students[i].scores[j] <= max) {
                    printStudent(students[i]);
                    found = 1;
                    break; // 只要有一门课程在范围内就显示
                }
            }
        }
        break;
    }
    default:
        printf("\033[1;31m无效选择！\033[0m\n");
        return;
    }

    if (!found) {
        printf("\n\033[1;31m未找到匹配的学生记录！\033[0m\n");
    }
}

void statistics() {
    int choice;
    printf("\n\033[1;36m----- 统计功能 -----\033[0m\n");
    printf("1. 学生总分和平均分\n");
    printf("2. 课程平均成绩\n");
    printf("3. 成绩段人数统计\n");
    printf("请选择统计项目 (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: { // 学生总分和平均分
        char id[15];
        printf("请输入学生学号: ");
        scanf("%s", id);

        int found = 0;
        for (int i = 0; i < studentCount; i++) {
            if (strcmp(students[i].id, id) == 0) {
                printf("\n\033[1;33m%s 的统计信息:\033[0m\n", students[i].name);
                printf("总分: %.1f\n", students[i].total);
                printf("平均分: %.1f\n", students[i].average);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\033[1;31m未找到该学生！\033[0m\n");
        }
        break;
    }
    case 2: { // 课程平均成绩
        int course;
        printf("\n请选择课程:\n");
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            printf("%d. %s\n", i + 1, subjects[i]);
        }
        printf("请选择课程编号 (1-%d): ", NUM_SUBJECTS);
        scanf("%d", &course);

        if (course < 1 || course > NUM_SUBJECTS) {
            printf("\033[1;31m无效的课程编号！\033[0m\n");
            break;
        }
        int courseIndex = course - 1;
        float total = 0;
        int count = 0;
        float max = 0, min = 100;

        for (int i = 0; i < studentCount; i++) {
            float score = students[i].scores[courseIndex];
            total += score;
            count++;

            if (score > max) max = score;
            if (score < min) min = score;
        }

        if (count > 0) {
            float average = total / (float)count;
            printf("\n\033[1;33m%s 课程统计信息:\033[0m\n", subjects[courseIndex]);
            printf("平均分: %.2f\n", average);
            printf("最高分: %.1f\n", max);
            printf("最低分: %.1f\n", min);
        }
        else {
            printf("\033[1;31m没有学生记录！\033[0m\n");
        }
        break;
    }
    case 3: { // 成绩段人数统计
        int course;
        printf("\n请选择课程:\n");
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            printf("%d. %s\n", i + 1, subjects[i]);
        }
        printf("请选择课程编号 (1-%d): ", NUM_SUBJECTS);
        scanf("%d", &course);

        if (course < 1 || course > NUM_SUBJECTS) {
            printf("\033[1;31m无效的课程编号！\033[0m\n");
            break;
        }

        int courseIndex = course - 1;
        int ranges[5] = { 0 }; // 0-59, 60-69, 70-79, 80-89, 90-100

        for (int i = 0; i < studentCount; i++) {
            float score = students[i].scores[courseIndex];
            if (score < 60) ranges[0]++;
            else if (score < 70) ranges[1]++;
            else if (score < 80) ranges[2]++;
            else if (score < 90) ranges[3]++;
            else ranges[4]++;
        }

        printf("\n\033[1;33m%s 课程成绩分布:\033[0m\n", subjects[courseIndex]);
        printf("0-59分: %d人\n", ranges[0]);
        printf("60-69分: %d人\n", ranges[1]);
        printf("70-79分: %d人\n", ranges[2]);
        printf("80-89分: %d人\n", ranges[3]);
        printf("90-100分: %d人\n", ranges[4]);
        break;
    }
    default:
        printf("\033[1;31m无效选择！\033[0m\n");
    }
}

void sortStudents() {
    int choice;
    printf("\n\033[1;36m----- 排序功能 -----\033[0m\n");
    printf("1. 按学号排序\n");
    printf("2. 按总分排序\n");
    printf("3. 按单科成绩排序\n");
    printf("请选择排序方式 (1-3): ");
    scanf("%d", &choice);

    int courseIndex = -1;
    if (choice == 3) {
        printf("\n请选择课程:\n");
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            printf("%d. %s\n", i + 1, subjects[i]);
        }
        printf("请选择课程编号 (1-%d): ", NUM_SUBJECTS);
        scanf("%d", &choice);

        if (choice < 1 || choice > NUM_SUBJECTS) {
            printf("\033[1;31m无效的课程编号！\033[0m\n");
            return;
        }
        courseIndex = choice - 1;
        choice = 3; // 重置选择为3
    }

    // 使用选择排序算法
    for (int i = 0; i < studentCount - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < studentCount; j++) {
            int swap = 0;

            if (choice == 1) { // 按学号
                if (strcmp(students[j].id, students[maxIndex].id) < 0) {
                    maxIndex = j;
                }
            }
            else if (choice == 2) { // 按总分
                if (students[j].total > students[maxIndex].total) {
                    maxIndex = j;
                }
            }
            else if (choice == 3) { // 按单科成绩
                if (students[j].scores[courseIndex] > students[maxIndex].scores[courseIndex]) {
                    maxIndex = j;
                }
            }
        }

        if (maxIndex != i) {
            Student temp = students[i];
            students[i] = students[maxIndex];
            students[maxIndex] = temp;
        }
    }
    printf("\n\033[1;32m排序完成！\033[0m\n");
    displayAll();
}

void displayAll() {
    if (studentCount == 0) {
        printf("\n\033[1;31m没有学生记录！\033[0m\n");
        return;
    }

    printf("\n\033[1;36m----- 所有学生信息 -----\033[0m\n");
    printHeader();

    for (int i = 0; i < studentCount; i++) {
        printStudent(students[i]);
    }

    printf("\n\033[1;33m共 %d 名学生\033[0m\n", studentCount);
}

void printHeader() {
    printf("\n\033[1;35m%-12s %-10s %-15s", "学号", "姓名", "专业");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf(" %-8s", subjects[i]);
    }
    printf(" %-6s %-8s\033[0m\n", "总分", "平均分");
}

void printStudent(Student s) {
    printf("%-12s %-10s %-15s", s.id, s.name, s.major);
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf(" %-8.1f", s.scores[i]);  // 使用.1f显示一位小数
    }
    printf(" %-6.1f %-8.1f\n", s.total, s.average);  // 使用.1f显示一位小数
}

void clearInputBuffer() {
    while (getchar() != '\n');
}
