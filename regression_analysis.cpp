#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
double solution(double n, vector<pair<double,double> > & dataset) {

    for (int i = 0; i < dataset.size() - 1; i++) {
        if (n <= dataset[i + 1].first || i == dataset.size() - 2) {
            double a_error = dataset[i].second - dataset[i].first;
            double b_error = dataset[i + 1].second - dataset[i + 1].first;
            return
                n + (a_error
                    - ((a_error - b_error) * (
                            (n - dataset[i].first) /
                            (dataset[i + 1].first - dataset[i].first))
                        )
                    );
        }
    }

    //error
    return -1;
}
int main() 
{
 vector<pair <double, double> > dataset
    (
        {
        {0, 0} ,
        {40000, 39900,} ,
        {80000, 79960} ,
        {120000, 120040},
        {160000, 160080},
        {190000, 190150}
        }
    );
   
    
   printf("\n---------------------------------------------------\n\n");
    printf("실오차 비례 정격하중(0~196.1 kN) 예측 프로그램\n\n");
    printf("이 프로그램에 쓰인 데이터셋은 다음과 같고,\n\n"); 
    printf("---------------------------------------------------\n\n");
    printf(" 지시값(N)     실제값(N)\n\n");
    for (int i=0; i<dataset.size(); i++)
    {
        printf("%10.2lf | %10.2lf\n", dataset[i],dataset[i]);
    }
    printf("\n");
    printf("---------------------------------------------------\n\n");
    printf("지시값(눈금값) 입력 시 각 구간별 오차를 회귀 예측해 오차 반영 실제값을 출력합니다. \n\n");     
    printf("1부터 196100까지의 실수(N)를 입력하세요.\n\n");
    
    double n;
    while (true) 
    {
        scanf("%lf", &n);
        printf("%.3lf\n\n", solution(n,dataset));
    }

    return 0;
}