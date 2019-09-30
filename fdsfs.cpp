using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace OSLab1
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            string choose;
            var processes = new List<Process>();
            var paused = new List<bool>();
            var killed = new List<bool>();
            var startTime = new List<DateTime>();
            var endTime = new List<DateTime>();


            do
            {
                Console.ForegroundColor = ConsoleColor.Green;
                Console.Write("\n\nMenu:\n");
                Console.ForegroundColor = ConsoleColor.White;
                Console.WriteLine("\t1. Start process(es).");
                Console.WriteLine("\t2. Pause process.");
                Console.WriteLine("\t3. Play process.");
                Console.WriteLine("\t4. Kill process.");
                Console.WriteLine("\t5. Change priority.");
                Console.WriteLine("\t6. Print table.");
                Console.WriteLine("\t0. Exit.");
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.Write(">>> ");
                Console.ForegroundColor = ConsoleColor.White;

                choose = Console.ReadLine();

                switch (choose)
                {
                    case "1": //Start
                        try
                        {
                            Console.ForegroundColor = ConsoleColor.Yellow;
                            Console.Write("Enter number of processes: ");
                            Console.ForegroundColor = ConsoleColor.White;
                            int processesNumber = int.Parse(Console.ReadLine());

                            for (int i = 0; i < processesNumber; i++)
                            {
                                var temp = Process.Start(@"C:\Users\Prkour228\Desktop\OSFunc\Release\OSFunc.exe");
                                processes.Add(temp);
                                paused.Add(false);
                                killed.Add(false);
                                startTime.Add(DateTime.Now);
                                endTime.Add(DateTime.Now);
                            }
                        }
                        catch (FormatException)
                        {
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.WriteLine("\nIncorrect format.");
                            Console.ForegroundColor = ConsoleColor.White;
                        }

                        break;
                    case "2": //Pause
                        try
                        {
                            Console.ForegroundColor = ConsoleColor.Yellow;
                            Console.Write("Enter index of processes: ");
                            Console.ForegroundColor = ConsoleColor.White;
                            int processesIndex = int.Parse(Console.ReadLine());
                            processes[processesIndex].SuspendProcess();
                            paused[processesIndex] = true;
                            Console.WriteLine("Process {0} friezed.", processes[processesIndex].Id);
                        }
                        catch (FormatException)
                        {
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.WriteLine("\nIncorrect format.\n");
                            Console.ForegroundColor = ConsoleColor.White;
                        }
                        catch (ArgumentOutOfRangeException)
                        {
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.WriteLine("\nIndex out of range.\n");
                            Console.ForegroundColor = ConsoleColor.White;
                        }

                        break;
                    case "3": //Play
                        try
                        {
                            Console.ForegroundColor = ConsoleColor.Yellow;
                            Console.Write("Enter index of processes: ");
                            Console.ForegroundColor = ConsoleColor.White;
                            int processesIndex = int.Parse(Console.ReadLine());
                            processes[processesIndex].ResumeProcess();
                            paused[processesIndex] = false;
                            Console.WriteLine("Process {0} play.", processes[processesIndex].Id);
                        }
                        catch (FormatException)
                        {
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.WriteLine("\nIncorrect format.\n");
                            Console.ForegroundColor = ConsoleColor.White;
                        }
                        catch (ArgumentOutOfRangeException)
                        {
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.WriteLine("\nIndex out of range.\n");
                            Console.ForegroundColor = ConsoleColor.White;
                        }

                        break;
                    case "4": //Kill
                        try
                        {
                            Console.ForegroundColor = ConsoleColor.Yellow;
                            Console.Write("Enter index of processes: ");
                            Console.ForegroundColor = ConsoleColor.White;
                            int processesIndex = int.Parse(Console.ReadLine());
                            killed[processesIndex] = true;
                            endTime[processesIndex] = DateTime.Now;
                            processes[processesIndex].Kill();
                            Console.WriteLine("Process {0} killed.", processes[processesIndex].Id);
                        }
                        catch (FormatException)
                        {
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.WriteLine("\nIncorrect format.\n");
                            Console.ForegroundColor = ConsoleColor.White;
                        }
                        catch (ArgumentOutOfRangeException)
                        {
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.WriteLine("\nIndex out of range.\n");
                            Console.ForegroundColor = ConsoleColor.White;
                        }

                        break;
                    case "5": //Change
                        try
                        {
                            Console.ForegroundColor = ConsoleColor.Yellow;
                            Console.Write("Enter index of processes: ");
                            Console.ForegroundColor = ConsoleColor.White;
                            int processesIndex = int.Parse(Console.ReadLine());

                            Console.WriteLine("\nNew priority:");
                            Console.WriteLine("\t1. Idle.");
                            Console.WriteLine("\t2. High.");
                            Console.WriteLine("\t3. RealTime.");
                            Console.WriteLine("\t4. BelowNormal.");
                            Console.WriteLine("\t5. AboveNormal.");
                            Console.ForegroundColor = ConsoleColor.Yellow;
                            Console.Write(">>> ");
                            Console.ForegroundColor = ConsoleColor.White;

                            switch (Console.ReadLine())
                            {
                                case "1":
                                    processes[processesIndex].PriorityClass = ProcessPriorityClass.Idle;
                                    break;
                                case "2":
                                    processes[processesIndex].PriorityClass = ProcessPriorityClass.High;
                                    break;
                                case "3":
                                    processes[processesIndex].PriorityClass = ProcessPriorityClass.RealTime;
                                    break;
                                case "4":
                                    processes[processesIndex].PriorityClass = ProcessPriorityClass.BelowNormal;
                                    break;
                                case "5":
                                    processes[processesIndex].PriorityClass = ProcessPriorityClass.AboveNormal;
                                    break;
                                default:
                                    Console.ForegroundColor = ConsoleColor.Red;
                                    Console.WriteLine("\nInvalid menu item.\n");
                                    Console.ForegroundColor = ConsoleColor.White;
                                    break;
                            }

                            Console.WriteLine("Process {0} have priority {1}.", processes[processesIndex].Id,
                                processes[processesIndex].PriorityClass.ToString());
                        }
                        catch (FormatException)
                        {
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.WriteLine("\nIncorrect format.\n");
                            Console.ForegroundColor = ConsoleColor.White;
                        }
                        catch (ArgumentOutOfRangeException)
                        {
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.WriteLine("\nIndex out of range.\n");
                            Console.ForegroundColor = ConsoleColor.White;
                        }

                        break;
                    case "6": //Print
                        if (processes.Count == 0)
                        {
                            Console.WriteLine("\nList of processes is empty.");
                            break;
                        }

                        Console.WriteLine("name\tlocal index\tpid\tworking\t\ttime\t\t\tpriority");

                        for (int i = 0; i < processes.Count; i++)
                        {
                            try
                            {
                                Console.Write("{0}\t{1}\t\t{2}\t", processes[i].ProcessName, i,
                                    processes[i].Id);
                                if (killed[i])
                                {
                                    Console.WriteLine("Killed\t\t{0}\t{1}", endTime[i] - startTime[i], 
                                        processes[i].PriorityClass.ToString());
                                }
                                else if (paused[i])
                                {
                                    Console.Write("Paused\t\t");
                                    Console.WriteLine("{0}\t{1}", DateTime.Now - endTime[i], 
                                        processes[i].PriorityClass.ToString());
                                }
                                else
                                {
                                    Console.Write(processes[i].Responding.ToString() + "\t\t");
                                    Console.WriteLine("{0}\t{1}", DateTime.Now - endTime[i], 
                                        processes[i].PriorityClass.ToString());
                                }
                            }
                            catch (InvalidOperationException)
                            {
                                Console.WriteLine("{0}\t{1}\t\t{2}\t{3}\t\t{4}\t{5}", "Killed", i,
                                    "Killed",
                                    "Killed", endTime[i] - startTime[i],
                                    "\t\tKilled");
                            }
                        }

                        break;
                    default:
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.WriteLine("\nInvalid menu item.");
                        Console.ForegroundColor = ConsoleColor.White;
                        break;
                }
            } while (choose != "0");

            Console.WriteLine("\n\nGood bye!");
        }
    }
}
