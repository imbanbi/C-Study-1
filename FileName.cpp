#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wchar.h>
#include <windows.h>
#include <tchar.h>
#include <conio.h>
#include <windows.h>  // ���� Sleep ����ͷ�ļ�

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    wchar_t name[50];
    wchar_t gender[10];
    wchar_t birth[15];
    wchar_t education[30];
    wchar_t position[30];
    wchar_t phone[20];
    wchar_t address[100];
} Employee;

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

// ����������
void drawMainMenu() {
    setbkmode(TRANSPARENT);
    setbkcolor(WHITE);  // ���ñ���Ϊ��ɫ

    settextcolor(BLACK);  // ����������ɫΪ��ɫ
    TCHAR s1[] = _T("ManageSyetem");
    outtextxy(250, 50, s1);
     
    // ���ư�ť
    setfillcolor(RGB(102, 204, 255));  // ���ð�ť��ɫ
    bar(200, 150, 600, 200);  // ���ư�ť����
    rectangle(200, 150, 600, 200);  // ���ư�ť�߿�
    TCHAR s2[] = _T("insert");
    outtextxy(310, 160, s2);

    bar(200, 220, 600, 270); 
    rectangle(200, 220, 600, 270); 
    TCHAR s8[] = _T("research");
    outtextxy(310, 230, s8);

    bar(200, 290, 600, 340); 
    rectangle(200, 290, 600, 340); 
    TCHAR s7[] = _T("delete");
    outtextxy(310, 300, s7);

    bar(200, 360, 600, 410);
    rectangle(200, 360, 600, 410);
    TCHAR s3[] = _T("arrangem");
    outtextxy(310, 370, s3);

    bar(200, 430, 600, 480); 
    rectangle(200, 430, 600, 480); 
    TCHAR s5[] = _T("show");
    outtextxy(310, 440, s5);

    bar(200, 500, 600, 550);  
    rectangle(200, 500, 600, 550); 
    TCHAR s6[] = _T("update");
    outtextxy(310, 510, s6);

    bar(200, 570, 600, 620); 
    rectangle(200, 570, 600, 620); 
    TCHAR s99[] = _T("exit");
    outtextxy(310, 580, s99);
}


// ��������
int detectButtonClick(int x, int y) {
    if (x >= 200 && x <= 600) {
        if (y >= 150 && y <= 200) return 1;  // ����
        if (y >= 220 && y <= 270) return 2;  // ��ѯ
        if (y >= 290 && y <= 340) return 3;  // ɾ��
        if (y >= 360 && y <= 410) return 4;  // ����
        if (y >= 430 && y <= 480) return 5;  // ��ʾȫ��
        if (y >= 500 && y <= 550) return 6;  // ����
        if (y >= 570 && y <= 620) return 7;  // �˳�
    }
    return 0;
}



// Ա����Ϣ����
void insertEmployeeGUI() {
    cleardevice();
    settextstyle(20, 0, _T("Consolas"));

    TCHAR prompt[] = _T("Please input the information of the employee");
    outtextxy(100, 50, prompt);

    // �������ʾ�ı�
    outtextxy(100, 120, _T("ID:"));
    outtextxy(100, 170, _T("NAME:"));
    outtextxy(100, 220, _T("GENDER:"));
    outtextxy(100, 270, _T("BIRTH:"));
    outtextxy(100, 320, _T("EDUCATION:"));
    outtextxy(100, 370, _T("POSITION:"));
    outtextxy(100, 420, _T("PHONE:"));
    outtextxy(100, 470, _T("ADDERSS:"));

    // ��ȡ�û�����
    settextcolor(BLACK);
    wchar_t idStr[20];
    InputBox(idStr, 20, L"Please input the ID:");
    employees[employeeCount].id = _wtoi(idStr);

    InputBox(employees[employeeCount].name, sizeof(employees[employeeCount].name) / sizeof(wchar_t), L"Please input the name:");
    InputBox(employees[employeeCount].gender, sizeof(employees[employeeCount].gender) / sizeof(wchar_t), L"Please input the gender:");
    InputBox(employees[employeeCount].birth, sizeof(employees[employeeCount].birth) / sizeof(wchar_t), L"Please input the birth:");
    InputBox(employees[employeeCount].education, sizeof(employees[employeeCount].education) / sizeof(wchar_t), L"Please input the education:");
    InputBox(employees[employeeCount].position, sizeof(employees[employeeCount].position) / sizeof(wchar_t), L"Please input the position:");
    InputBox(employees[employeeCount].phone, sizeof(employees[employeeCount].phone) / sizeof(wchar_t), L"Please input the phone:");
    InputBox(employees[employeeCount].address, sizeof(employees[employeeCount].address) / sizeof(wchar_t), L"Please input the address:");

    employeeCount++;
    MessageBoxW(NULL, L"����ɹ���", L"��ʾ", MB_OK);
    cleardevice();  // �����Ļ����
}

// ɾ��Ա��
void deleteEmployeeGUI() {
    cleardevice();
    wchar_t deleteKey[50];
    int found = 0;

    cleardevice();
    outtextxy(100, 100, _T("Please input the ID of the emplopyee you want to delete:"));
    InputBox(deleteKey, sizeof(deleteKey) / sizeof(wchar_t), L"������:");

    int deleteId = _wtoi(deleteKey);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == deleteId) {
            found = 1;
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            MessageBoxW(NULL, L"ɾ���ɹ���", L"��ʾ", MB_OK);
            return;
        }
    }
    if (!found) {
        MessageBoxW(NULL, L"δ�ҵ���Ա����Ϣ", L"��ʾ", MB_OK);
    }
    cleardevice(); 
}

// ����Ա��
int compareEmployees(const Employee* a, const Employee* b, int key) {
    switch (key) {
    case 1: return a->id - b->id;  // �����
    case 2: return wcscmp(a->name, b->name);  // ������
    case 3: return wcscmp(a->gender, b->gender);  // ���Ա�
    case 4: return wcscmp(a->birth, b->birth);  // ����������
    case 5: return wcscmp(a->education, b->education);  // ��ѧ��
    case 6: return wcscmp(a->position, b->position);  // ��ְ��
    case 7: return wcscmp(a->phone, b->phone);  // ���绰
    case 8: return wcscmp(a->address, b->address);  // ��סַ
    default: return 0;
    }
}

void sortEmployeesByKey(int key) {
    for (int i = 0; i < employeeCount - 1; i++) {
        for (int j = 0; j < employeeCount - i - 1; j++) {
            if (compareEmployees(&employees[j], &employees[j + 1], key) > 0) {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
    MessageBoxW(NULL, L"������ɣ�", L"��ʾ", MB_OK);
}

// ����GUI����
void sortEmployeesGUI() {
    wchar_t inputBuffer[10];  // �洢������ַ���
    int sortKey;
    cleardevice();

    outtextxy(100, 100, _T("Select the keywords to sort by: 1 - Number, 2 - Name, 3 - Gender, 4 - Date of Birth, 5 - Education, 6 - Position, 7 - Telephone, 8 - Address"));
    
    // ʹ�� InputBox ��ȡ�û�����
    InputBox(inputBuffer, sizeof(inputBuffer) / sizeof(wchar_t), L"Please input the keywords you choose:");

    // ��������ַ���ת��Ϊ����
    sortKey = _wtoi(inputBuffer);  // ʹ�� _wtoi �� wchar_t ת��Ϊ int

    // �ж������Ƿ���Ч
    if (sortKey >= 1 && sortKey <= 8) {
        sortEmployeesByKey(sortKey);
    } else {
        MessageBoxW(NULL, L"��Чѡ�", L"��ʾ", MB_OK);
    }
    cleardevice();  // �����Ļ����
}


// ��ʾԱ����Ϣ

void showAllEmployeesGUI() {
    cleardevice();
    outtextxy(100, 50, _T("The list of employee information:"));

    int y = 100;
    for (int i = 0; i < employeeCount; i++) {
        wchar_t info[300];  // ʹ�� wchar_t ����

        // ʹ�� swprintf ��ʽ���ַ���
        swprintf(info, sizeof(info) / sizeof(wchar_t),
            L"ID: %d  NAME: %s  GENDER: %s  BIRTH: %s  EDUCATION: %s  POSITION: %s  PHONE: %s  ADDRESS: %s",
            employees[i].id, employees[i].name, employees[i].gender, employees[i].birth,
            employees[i].education, employees[i].position, employees[i].phone, employees[i].address);

        // ת��Ϊ TCHAR ����
        TCHAR tInfo[300];

#ifdef _UNICODE
        // ����� Unicode ���룬TCHAR �� wchar_t һ��������ֱ�Ӹ���
        wcscpy_s(tInfo, info);
#else
        // ����� ANSI ���룬ʹ�� wcstombs �� wchar_t ת��Ϊ char
        wcstombs(tInfo, info, sizeof(tInfo) / sizeof(TCHAR));
#endif

        // ʹ�� outtextxy ��ʾ
        outtextxy(100, y, tInfo);
        y += 50;  // ÿ�м��

        // �ӳ� 2500 ���룬ȷ��ÿ����ʾ��ʱ���㹻
        Sleep(2500);  // ����
    }

    if (employeeCount == 0) {
        MessageBoxW(NULL, L"��ǰ��Ա����Ϣ��", L"��ʾ", MB_OK);
    }
    cleardevice();  // �����Ļ����
}


// ��ѯ
int matchesCriteria(const Employee* emp, int key, const wchar_t* value) {
    if (value == NULL || value[0] == L'\0') {
        return 0;  // �����ѯֵΪ�գ��򷵻ز�ƥ��
    }

    wprintf(L"Comparing %d with %s\n", emp->id, value);  // ��ӡ�Ƚ���Ϣ
    switch (key) {
    case 1: return emp->id == _wtoi(value);  // ���
    case 2: return wcscmp(emp->name, value) == 0;  // ����
    case 3: return wcscmp(emp->gender, value) == 0;  // �Ա�
    case 4: return wcscmp(emp->birth, value) == 0;  // ��������
    case 5: return wcscmp(emp->education, value) == 0;  // ѧ��
    case 6: return wcscmp(emp->position, value) == 0;  // ְ��
    case 7: return wcscmp(emp->phone, value) == 0;  // �绰
    case 8: return wcscmp(emp->address, value) == 0;  // סַ
    default: return 0;
    }
}


void searchEmployeesByKey(int key, const wchar_t* value) {
    int found = 0;
    cleardevice();
    settextstyle(20, 0, _T("Consolas"));
    outtextxy(100, 100, L"The result:");

    int y = 150;
    for (int i = 0; i < employeeCount; i++) {
        if (matchesCriteria(&employees[i], key, value)) {
            wchar_t info[300];
            swprintf(info, sizeof(info) / sizeof(wchar_t),
                L"ID: %d  NAME: %s  GENDER: %s  BIRTH: %s  EDUCATION: %s  POSITION: %s  PHONE: %s  ADDRESS: %s",
                employees[i].id, employees[i].name, employees[i].gender, employees[i].birth,
                employees[i].education, employees[i].position, employees[i].phone, employees[i].address);

            outtextxy(100, y, info);
            y += 50;
            found = 1;
            Sleep(3000);
            cleardevice();  // �����Ļ����
        }
    }

    if (!found) {
        MessageBoxW(NULL, L"δ�ҵ�����������Ա��", L"��ʾ", MB_OK);
    }
}


void searchEmployeeGUI() {
    int searchKey;
    wchar_t searchKeyStr[10];  // �洢����Ŀ��ַ���
    wchar_t searchValue[50];

    cleardevice();
    outtextxy(100, 100, _T("Select the keywords to sort by: 1 - ID, 2 - Name, 3 - Gender, 4 - Date of Birth, 5 - Education, 6 - Position, 7 - Telephone, 8 - Address"));

    // ��ȡ����Ϊ���ַ���
    InputBox(searchKeyStr, sizeof(searchKeyStr) / sizeof(wchar_t), L"Please input the keyword you choose:");

    // ת��Ϊ����
    if (swscanf_s(searchKeyStr, L"%d", &searchKey) == 1 && searchKey >= 1 && searchKey <= 8) {
        InputBox(searchValue, sizeof(searchValue) / sizeof(wchar_t), L"Please input the value you want to search:");
        searchEmployeesByKey(searchKey, searchValue);
    }
    else {
        MessageBoxW(NULL, L"��Чѡ�", L"��ʾ", MB_OK);
    }
    cleardevice();  // �����Ļ����
}

//������Ϣ
void updateEmployeeGUI() {
    cleardevice();
    wchar_t updateKey[20];
    int found = 0;

    outtextxy(100, 100, _T("Please input the ID of the employee you want to update:"));
    InputBox(updateKey, sizeof(updateKey) / sizeof(wchar_t), L"������Ҫ���µ�Ա����ţ�");

    int updateId = _wtoi(updateKey);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == updateId) {
            found = 1;

            // ��ʾ��ǰԱ����Ϣ
            wchar_t info[300];
            swprintf(info, sizeof(info) / sizeof(wchar_t),
                     L"��ǰ��Ϣ: ID: %d, NAME: %s, GENDER: %s, BIRTH: %s, EDUCATION: %s, POSITION: %s, PHONE: %s, ADDRESS: %s",
                     employees[i].id, employees[i].name, employees[i].gender, employees[i].birth,
                     employees[i].education, employees[i].position, employees[i].phone, employees[i].address);
            MessageBoxW(NULL, info, L"��ǰԱ����Ϣ", MB_OK);

            // �����ֶ�
            InputBox(employees[i].name, sizeof(employees[i].name) / sizeof(wchar_t), L"�������µ�������");
            InputBox(employees[i].gender, sizeof(employees[i].gender) / sizeof(wchar_t), L"�������µ��Ա�");
            InputBox(employees[i].birth, sizeof(employees[i].birth) / sizeof(wchar_t), L"�������µĳ������ڣ�");
            InputBox(employees[i].education, sizeof(employees[i].education) / sizeof(wchar_t), L"�������µ�ѧ����");
            InputBox(employees[i].position, sizeof(employees[i].position) / sizeof(wchar_t), L"�������µ�ְ��");
            InputBox(employees[i].phone, sizeof(employees[i].phone) / sizeof(wchar_t), L"�������µĵ绰��");
            InputBox(employees[i].address, sizeof(employees[i].address) / sizeof(wchar_t), L"�������µĵ�ַ��");

            MessageBoxW(NULL, L"���³ɹ���", L"��ʾ", MB_OK);
            cleardevice();
            return;
        }
    }

    if (!found) {
        MessageBoxW(NULL, L"δ�ҵ���Ա����Ϣ", L"��ʾ", MB_OK);
    }
    cleardevice();
}


int main() {
    initgraph(1400, 800);  // ��ʼ������
    int choice;
    cleardevice();  // �����Ļ����
    while (1) {
        drawMainMenu();  // ����������

        // ���������¼�
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN) {
            choice = detectButtonClick(msg.x, msg.y);

            switch (choice) {
            case 1:
                insertEmployeeGUI();  // ����Ա��
                break;
            case 2:
                searchEmployeeGUI();  // ��ѯԱ��
                break;
            case 3:
                deleteEmployeeGUI();  // ɾ��Ա��
                break;
            case 4:
                sortEmployeesGUI();  // ����Ա��
                break;
            case 5:
                showAllEmployeesGUI();  // ��ʾȫ��Ա��
                break;
            case 6:
                updateEmployeeGUI();  // ����Ա��
                break;
            case 7:
                closegraph();  // �˳�ϵͳ
                return 0;
            default:
                break;
            }
        }

    }
}
