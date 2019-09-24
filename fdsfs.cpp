#include <bits/stdc++.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <chrono>


#define WINDOWS_TICK 10000000
#define SEC_TO_UNIX_EPOCH 11644473600LL
#define NUMBER_OF_PRIORITIES 8

typedef long long ll;
typedef long double ld;

using namespace std;
using namespace std::chrono;

unsigned WindowsTickToUnixSeconds(ll windowsTicks)
{
    return (unsigned)(windowsTicks / WINDOWS_TICK - SEC_TO_UNIX_EPOCH);
}

int NUMBER_OF_PROCESSES;

int main()
{
    STARTUPINFO startupinfo;
    ZeroMemory(&startupinfo,sizeof(STARTUPINFO));
    PROCESS_INFORMATION process_information = {nullptr};

    printf("Input the number of the processes\n");
    cin >> NUMBER_OF_PROCESSES;

    auto start = high_resolution_clock::now();


    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    if( hSnap == INVALID_HANDLE_VALUE )
    {
        return( FALSE );
    }

    HANDLE PROCESSES[NUMBER_OF_PROCESSES];
    DWORD pids[NUMBER_OF_PROCESSES];
    HANDLE THREADS[NUMBER_OF_PROCESSES];
    DWORD tids[NUMBER_OF_PROCESSES];

    DWORD PRIORITIES[NUMBER_OF_PRIORITIES] = {ABOVE_NORMAL_PRIORITY_CLASS, BELOW_NORMAL_PRIORITY_CLASS,
                           HIGH_PRIORITY_CLASS, IDLE_PRIORITY_CLASS, NORMAL_PRIORITY_CLASS, PROCESS_MODE_BACKGROUND_BEGIN,
                           PROCESS_MODE_BACKGROUND_END, REALTIME_PRIORITY_CLASS,
                           };

    for( int i = 0; i < NUMBER_OF_PROCESSES; i++)
    {
        BOOL process = CreateProcess(TEXT("C:\\Users\\Admin\\CLionProjects\\newAlgo\\cmake-build-debug\\labs0ss.exe"),
                                     NULL, NULL,
                                     NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &startupinfo, &process_information);
        if (!process)
        {
            cout << "Something went wrong..." << endl;
            return 1;
        }
        PROCESSES[i] = process_information.hProcess;
        pids[i] = process_information.dwProcessId;
        THREADS[i] = process_information.hThread;
        tids[i] = process_information.dwThreadId;
    }

        int task,index;
        bool looper = true;
        while (looper)
        {
            printf("~~~|| Processes control menu ||~~~\n\n");
            printf("1 - Stop the chosen process\n");
            printf("2 - Start the chosen process\n");
            printf("3 - Complete the chosen process\n");
            printf("4 - Kill the chosen process\n");
            printf("5 - Set priorities of processes\n");
            printf("6 - Set priority of the chosen process\n");
            printf("7 - Get the information about the chosen process\n");
            printf("8 - Exit from the menu and check the time\n");
            printf("9 - Exit from the program\n\n");
            printf("~~~|| Processes control menu ||~~~\n\n");
            printf("Select the command: ");
            cin >> task;
            switch (task){
                case 1:
                    printf("Stop the process. Select an id: ");
                    cin >> index;
                    SuspendThread(THREADS[index-1]);
                    printf("Done!\n");
                    break;
                case 2:
                    printf("Continue the process. Select an id: ");
                    cin >> index;
                    ResumeThread(THREADS[index-1]);
                    if(ResumeThread(THREADS[index-1]) == DWORD(0)){
                        printf("The chosen process hasn`t been suspended yet!");
                    }else if(ResumeThread(THREADS[index-1]) == DWORD(1)){
                        printf("The chosen process has already been resumed!");
                    }
                    else if(ResumeThread(THREADS[index-1]) > DWORD(1)){
                        printf("The chosen process is still suspended!");
                    }
                    printf("Done!\n");
                    break;
                case 3:
                    printf("Complete the process. Select an id: ");
                    cin >> index;
                    DWORD EXIT;
                    TerminateThread(THREADS[index-1],EXIT);
                    break;
                case 4:
                    printf("Kill the process. Select an id: ");
                    cin >> index;
                    TerminateProcess(PROCESSES[index-1],UINT (0));
                    printf("Done. The process number %d was terminated\n",index);
                    break;
                case 5:
                    printf("Changing priorities of %d processes....\n", NUMBER_OF_PROCESSES);
                    for(int i = 0; i < NUMBER_OF_PROCESSES; i++)
                    {
                        if((i+1)%2 == 0){
                            SetPriorityClass(PROCESSES[i],NORMAL_PRIORITY_CLASS);
                        } else{
                            SetPriorityClass(PROCESSES[i],REALTIME_PRIORITY_CLASS);
                        }
                    }
                    printf("Done!\n");
                    break;
                case 6:
                    printf("Select a process: ");
                    cin >> index;
                    int priority;
                    printf("Select a priority: ");
                    cin >> priority;
                    SetPriorityClass(PROCESSES[index-1],PRIORITIES[priority-1]);
                    printf("Done!\n");
                    if(priority > NUMBER_OF_PRIORITIES){
                        printf("Wrong priority input!\n");
                    }
                    break;
                case 7:
                    printf("Select an index to get more information: ");
                    cin >> index;
                    cout << PROCESSES[index-1] << " | " << pids[index-1] << " | " << GetPriorityClass(PROCESSES[index-1]) <<
                    " | " << tids[index-1] << endl;
                    printf("Done!\n");
                    break;
                case 8:
                    looper = false;
                    break;
                case 9:
                    printf("Bye!");
                    for(int i = 0; i < NUMBER_OF_PROCESSES; i++)
                    {
                        TerminateProcess(PROCESSES[i],UINT(0));
                    }
                    return 1;
                default:
                    printf("Wrong input!\n");
            }
        }

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << duration.count() / pow(10, 6) << endl;
    return 0;
}
