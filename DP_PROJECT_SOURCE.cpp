// #1.
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <tuple>
using namespace std;

class BaseBallGame
{
	typedef tuple<int, int, int> INPUT;
	typedef tuple<int, int> RESULT;
	vector<pair<INPUT, RESULT> > v;
public:
	BaseBallGame() { srand((unsigned)time(0)); }

	void run()
	{
		while (1)
		{
			//-----------------------------------------------
			// 이전의 결과가 담긴 vector v를 참고 해서
			// 사용자가 생각한 숫자를 예측해 냅니다.
			// 현재 구현은 무조건 랜덤 입니다.
			int x = 0, y = 0, z = 0;
			do {
				x = rand() % 9 + 1;
				y = rand() % 9 + 1;
				z = rand() % 9 + 1;
			} while (x == y || y == z || x == z);
			//--------------------------------------
			cout << "당신이 생각한 숫자는 " << x
				<< ", " << y << ", " << z << " 입니까 ?" << endl;
			int strike = 0, ball = 0;
			cout << "strike 갯수 : ";
			cin >> strike;
			if (strike == 3)
			{
				cout << "성공 !" << endl;
				break;
			}
			cout << "ball 갯수 : ";
			cin >> ball;
			//--------------------------------------
			// 입력된 결과(strike, ball)을 기록해 두었다가
			// 다음수를 예측할때 사용합니다.
			v.push_back(make_pair(INPUT(x, y, z), RESULT(strike, ball)));
			dump();
		}
	}
	// 필요하신 분을 위해 참고용으로 만든 함수입니다. 
	void dump()
	{
		printf("-------------------------------\n");
		printf("입력값   s b\n");
		for (auto& p : v) // p는 pair<INPUT, RESULT> 입니다.
		{
			printf(" %d %d %d : %d %d\n",
				get<0>(p.first), get<1>(p.first), get<2>(p.first),
				get<0>(p.second), get<1>(p.second));
		}
		printf("-------------------------------\n");
	}
};
int main(void)
{
	BaseBallGame bbg;
	bbg.run();
}

// #2
int main()
{
	// 조건 1. Folder와 File의 객체를 생성할 수 있어야 합니다.
	Folder* rootFolder = new Folder("ROOT"); // 폴더는 이름만 있습니다.
	Folder* aaaaFolder = new Folder("AAAA");
	Folder* bbbbFolder = new Folder("BBBB");

	File* file1 = new File("a.txt", 10); // 화일은 이름과 크기가 있습니다
	File* file2 = new File("b.txt", 20);
	File* file3 = new File("c.txt", 30);
	File* file4 = new File("d.txt", 40);


	// 조건 2. 폴더안에 파일 및 다른 폴더를 넣을 수 있어야 합니다.
	rootFolder->add(aaaaFolder);
	rootFolder->add(bbbbFolder);
	rootFolder->add(file1);

	aaaaFolder->add(file2);
	aaaaFolder->add(file3);

	bbbbFolder->add(file4);


	// 조건 3. 파일과 폴더 크기를 출력할 수 있어야 합니다.
	//         폴더는 자신만의 크기는 없지만 크기를 구할 수 는 있습니다.
	cout << file1->getSize() << endl; // 10
	cout << aaaaFolder->getSize() << endl; // 50
	cout << rootFolder->getSize() << endl; // 100


	// 조건 4. 화면 출력
	file1->print();			// 파일이므로 이름과 크기만 출력해 주세요. 
	// ex) (a.txt, 10)   

	rootFolder->print();	// ROOT폴더 전체의 모양을 보기좋게 출력해 주세요
	// [ROOT]
	//			[AAAA]
	//				(b.txt, 20)
	//				(b.txt, 30)
	//			[BBBB]
	//				(d.txt, 40)
	//			(a.txt, 10)	


// 조건 5. 폴더 제거시 폴더 안에 있는 모든 파일과 폴더가 제거 되게 해주세요
	delete rootFolder;
}



// #3
#include <iostream>
#include <list>
using namespace std;
int main()
{
	Queue<int> q;
	q.Push(10);
	q.Push(20);
	cout << q.Pop() << endl; // 10
	cout << q.Pop() << endl; // 20
}
