#include <iostream>
#include <string>
using namespace std;

int S, P;  // S: DNA 문자열 전체 길이 | P: 부분 문자열 길이
int required[4];  // 최소 필요한 A, C, G, T 개수
int current[4];  // 현재 윈도우 내 A, C, G, T 개수
string dna;  // 입력받은 DNA 문자열

int check() {  // 현재 부분 문자열이 조건을 만족하는지 검사하는 함수
    for (int i = 0; i < 4; i++) {
        if (current[i] < required[i]) return 0;  //하나라도 부족하면 0 return
    }
    return 1;  // 모든 조건 만족시 1 return
}

int main() {
    cin >> S >> P;
    cin >> dna;
    cin >> required[0] >> required[1] >> required[2] >> required[3];  // A, C, G, T 최소 개수 입력 받기

    int cnt = 0;

    for (int i = 0; i < P; i++) {  // 초기 윈도우(dna[0] ~ dna[P-1])의 문자 개수 세기
        switch (dna[i]) {
            case 'A': current[0]++; break;
            case 'C': current[1]++; break;
            case 'G': current[2]++; break;
            case 'T': current[3]++; break;
        }
    }
    cnt += check();  // 초기 윈도우가 조건을 만족하면 cnt 증가

    for (int i = P; i < S; i++) {  // 슬라이딩 윈도우: 한 칸씩 오른쪽으로 이동하며 검사
        switch (dna[i - P]) {  // 이전 윈도우에서 빠지는 문자 제거
            case 'A': current[0]--; break;
            case 'C': current[1]--; break;
            case 'G': current[2]--; break;
            case 'T': current[3]--; break;
        }

        switch (dna[i]) {  // 새로 들어오는 문자 추가
            case 'A': current[0]++; break;
            case 'C': current[1]++; break;
            case 'G': current[2]++; break;
            case 'T': current[3]++; break;
        }

        cnt += check();  // 현재 윈도우가 조건 만족하면 cnt 증가
    }

    cout << cnt << '\n';

    return 0;
}