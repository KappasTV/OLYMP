#include <bits/stdc++.h>
//#include <windows.h>
//#include <chrono>
//#define pb push_back
//using namespace std::chrono;
//using namespace std;
//typedef long long ll;
//int NUMBER_OF_THREADS;
//CRITICAL_SECTION critical_section;
//struct FUNC_ARGS{
//    int left;
//    int right;
//    vector<int>&array;
//};
//vector<ll> temporary;
//vector<vector<ll>>multi;
//void ShellSort(LPVOID p_args){
//    EnterCriticalSection(&critical_section);
//    auto *args = (FUNC_ARGS *) (p_args);
//    int size = args->right - args->left + 1;
//    for (int j = args->left; j <= args->right; j++) {
//        temporary.pb(args->array[j]);
//    }
//    for (int gap = size / 2; gap > 0; gap /= 2) {
//        for (int j = gap; j < size + 1; j++) {
//            ll temp = temporary[j];
//            int k;
//            for (k = j; k >= gap && temporary[k - gap] > temp; k -= gap) {
//                temporary[k] = temporary[k - gap];
//            }
//            temporary[k] = temp;
//        }
//    }
//    LeaveCriticalSection(&critical_section);
//}
//int main()
//{
//    printf("\nInput number of threads\n");
//    cin >> NUMBER_OF_THREADS;
//    printf("\nInput number of elements for each part\n");
//    int num;
//    cin >> num;
//    int NUMBER_OF_ELEMENTS = num * NUMBER_OF_THREADS;
//    vector<int> array_for_sort(static_cast<unsigned int>(NUMBER_OF_ELEMENTS));
//    auto start = high_resolution_clock::now();
//    printf("\nRandomization of the array\n");
//    for(int i = 0; i < NUMBER_OF_ELEMENTS; i++){
//        array_for_sort[i] = rand()%10000;
//        cout << array_for_sort[i] << " ";
//    }
//    cout << endl;
//    cout << endl;
//    HANDLE hThreads[NUMBER_OF_THREADS];
//    DWORD dwThread_ids[NUMBER_OF_THREADS];
//    int PRIORITIES[9] = {THREAD_MODE_BACKGROUND_BEGIN,THREAD_MODE_BACKGROUND_END,THREAD_PRIORITY_ABOVE_NORMAL
//            ,THREAD_PRIORITY_BELOW_NORMAL,THREAD_PRIORITY_HIGHEST,THREAD_PRIORITY_IDLE,
//                         THREAD_PRIORITY_LOWEST,THREAD_PRIORITY_NORMAL,THREAD_PRIORITY_TIME_CRITICAL};
//    int left = 1,right = num;
//    InitializeCriticalSection(&critical_section);
//    for(int i = 0; i < NUMBER_OF_THREADS; i++){
//        FUNC_ARGS args = {left-1,right-1,array_for_sort};
//        hThreads[i] = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ShellSort,&args,CREATE_SUSPENDED,&dwThread_ids[i]);
//        left = right+1;
//        right += num;
//    }
//    printf("\nThread`s creation completed\n");
//    bool looper = true;
//    int task;
//    int index;bool inner = true;
//    int priority;
//    while (looper){
//        printf("\n~~~|| Threads control menu ||~~~\n");
//        printf("1 - Run all the threads\n");
//        printf("2 - Print the results\n");
//        printf("2 - Set a priority of the chosen thread\n");
//        printf("3 - Exit from the menu and check the time\n");
//        printf("~~~|| Threads control menu ||~~~\n\n");
//        printf("Select the command : ");
//        cin >> task;
//        switch (task){
//            case 1:
//                for(int i = 0; i < NUMBER_OF_THREADS; i++){
//                    ResumeThread(hThreads[i]);
//                    WaitForSingleObject(hThreads[i], INFINITE);
//                    multi.push_back(temporary);
//                }
//                break;
//            case 2:
//                for(int i = 0; i < NUMBER_OF_THREADS; i++) {
//                    printf("\n||| Part # %d |||\n", i + 1);
//                    for(int j = 0; j <= i; j++ ){
//                        printf("\n~~~");
//                        sort(multi[j].begin(),multi[j].end());
//                        for(auto &item : multi[j]){
//                            cout << item << " ";
//                        }
//                        printf("~~~");
//                        printf("\n");
//                    }
//                }
//                break;
//            case 3:
//                printf("Input the index : ");
//                cin >> index;
//                while (inner) {
//                    printf("~~~|| Priorities menu ||~~~\n\n");
//                    printf("1 - THREAD_MODE_BACKGROUND_BEGIN\n");
//                    printf("2 - THREAD_MODE_BACKGROUND_END\n");
//                    printf("3 - THREAD_PRIORITY_ABOVE_NORMAL\n");
//                    printf("4 - THREAD_PRIORITY_BELOW_NORMAL\n");
//                    printf("5 - THREAD_PRIORITY_HIGHEST\n");
//                    printf("6 - THREAD_PRIORITY_IDLE\n");
//                    printf("7 - THREAD_PRIORITY_LOWEST\n");
//                    printf("8 - THREAD_PRIORITY_NORMAL\n");
//                    printf("9 - THREAD_PRIORITY_TIME_CRITICAL\n");
//                    printf("10 - Exit\n");
//                    printf("~~~|| Priorities menu ||~~~\n\n");
//                    printf("Choose the priority : ");
//                    cin >> priority;
//                    switch (priority){
//                        case 1:
//                            SetThreadPriority(hThreads[index-1],PRIORITIES[priority-1]);
//                            inner = false;
//                            break;
//                        case 2:
//                            SetThreadPriority(hThreads[index-1],PRIORITIES[priority-1]);
//                            inner = false;
//                            break;
//                        case 3:
//                            SetThreadPriority(hThreads[index-1],PRIORITIES[priority-1]);
//                            inner = false;
//                            break;
//                        case 4:
//                            SetThreadPriority(hThreads[index-1],PRIORITIES[priority-1]);
//                            inner = false;
//                            break;
//                        case 5:
//                            SetThreadPriority(hThreads[index-1],PRIORITIES[priority-1]);
//                            inner = false;
//                            break;
//                        case 6:
//                            SetThreadPriority(hThreads[index-1],PRIORITIES[priority-1]);
//                            inner = false;
//                            break;
//                        case 7:
//                            SetThreadPriority(hThreads[index-1],PRIORITIES[priority-1]);
//                            inner = false;
//                            break;
//                        case 8:
//                            SetThreadPriority(hThreads[index-1],PRIORITIES[priority-1]);
//                            inner = false;
//                            break;
//                        case 9:
//                            SetThreadPriority(hThreads[index-1],PRIORITIES[priority-1]);
//                            inner = false;
//                            break;
//                        case 10:
//                            inner = false;
//                            break;
//                        default:
//                            printf("Wrong input!");
//                    }
//                }
//                break;
//            case 4:
//                looper = false;
//                break;
//            default:
//                printf("Wrong input!");
//        }
//    }
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
//    printf("Execution time - %lf seconds\n",duration.count()/pow(10,6));
//    return 0;
//}
