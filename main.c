#include <stdio.h>

// Define a structure for Date
struct Date {
    int dd, mm, yy;
};

// Define a structure for Employee
struct Employee {
    int Empno;
    char EmpName[50];
    struct Date hiredate;
    float BasicSalary;
    float NetSalary;
};

// Function to accept data for multiple employees
void AcceptEmployeeData(struct Employee employees[], int numEmployees) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        employees[i].Empno = i + 1; // Assign a unique employee number
        printf("Enter Employee Name: ");
        scanf("%s", &employees[i].EmpName);
        printf("Enter Hire Date (dd mm yyyy): ");
        scanf("%d %d %d", &employees[i].hiredate.dd, &employees[i].hiredate.mm, &employees[i].hiredate.yy);
        printf("Enter Basic Salary: ");
        scanf("%f", &employees[i].BasicSalary);
    }
}

// Function to calculate net pay for multiple employees
void CalculateNetPay(struct Employee employees[], int numEmployees) {
    for (int i = 0; i < numEmployees; i++) {
        employees[i].NetSalary = employees[i].BasicSalary - (0.4 * employees[i].BasicSalary) - (0.1 * employees[i].BasicSalary) - (0.05 * employees[i].BasicSalary);
    }
}

// Function to display data for multiple employees
void ShowEmployeeData(struct Employee employees[], int numEmployees) {
    printf("\nEmployee Details:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("\nEmployee Number: %d\n", employees[i].Empno);
        printf("Employee Name: %s\n", employees[i].EmpName);
        printf("Hire Date: %02d/%02d/%04d\n", employees[i].hiredate.dd, employees[i].hiredate.mm, employees[i].hiredate.yy);
        printf("Basic Salary: $%.2f\n", employees[i].BasicSalary);
        printf("Net Salary: $%.2f\n", employees[i].NetSalary);
    }
}

int main() {
    int numEmployees;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    struct Employee employees[numEmployees];

    AcceptEmployeeData(employees, numEmployees);
    CalculateNetPay(employees, numEmployees);
    ShowEmployeeData(employees, numEmployees);

    return 0;
}
