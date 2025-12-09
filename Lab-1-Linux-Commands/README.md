# LINUX COMMANDS LAB REPORT

**Course:** Operating Systems Lab  
**Date:** December 9, 2025  
**Submitted by:** [Your Name]  
**Roll No:** [Your Roll Number]

---

## INTRODUCTION

### 1. What is Linux?

Linux is a free and open-source Unix-like operating system kernel first created by Linus Torvalds in 1991. It forms the core of various Linux distributions (distros) such as Ubuntu, Fedora, Debian, and CentOS. Linux is known for its stability, security, and flexibility, making it the preferred choice for servers, embedded systems, supercomputers, and increasingly for desktop environments.

The Linux operating system consists of three main components:
- **Kernel:** The core that manages system resources, memory, processes, and hardware
- **System Libraries:** Special functions and programs that applications use to access kernel features
- **System Utilities:** Programs that perform specialized management tasks

Linux follows a multi-user, multitasking architecture where multiple users can work simultaneously, and multiple processes can run concurrently. This makes it ideal for studying operating system concepts like process management, memory management, file systems, and inter-process communication.

### 2. The Linux Hierarchical File System

Linux uses a hierarchical tree-like file system structure, starting from the root directory denoted by `/`. Unlike Windows with multiple drive letters (C:, D:, etc.), everything in Linux exists under a single root directory. Key directories include:

- **/ (root):** The top-level directory of the entire file system
- **/home:** Contains personal directories for all users
- **/bin:** Essential binary executables and commands
- **/sbin:** System binaries used for system administration
- **/etc:** Configuration files for the system and applications
- **/var:** Variable data like logs, temporary files, and databases
- **/tmp:** Temporary files that are deleted on reboot
- **/usr:** User programs, libraries, and documentation
- **/proc:** Virtual file system providing process and system information
- **/dev:** Device files representing hardware components
- **/lib:** Shared library files needed by system programs

This hierarchical structure provides a clear organization and makes navigation logical and efficient.

### 3. Importance of Linux Commands in Operating Systems

Understanding Linux commands is crucial for operating system studies because:

**Process Management:** Linux commands allow direct interaction with the kernel for creating, monitoring, and terminating processes, which is fundamental to understanding CPU scheduling, context switching, and process states.

**Memory Management:** Commands help visualize physical and virtual memory usage, buffer caches, and swap space, demonstrating concepts like paging, segmentation, and memory allocation.

**File System Operations:** Through commands, students can explore inode structures, file permissions, directory hierarchies, and understand how the OS manages persistent storage.

**System Calls and APIs:** Many Linux commands are wrappers around system calls, providing practical insight into how user space interacts with kernel space.

**Concurrency and Synchronization:** Commands for managing threads and processes demonstrate real-world implementations of synchronization mechanisms, deadlock scenarios, and race conditions.

**Performance Analysis:** Monitoring commands reveal bottlenecks, resource utilization, and system performance metrics essential for optimization.

For computer science students, mastering Linux commands bridges the gap between theoretical OS concepts and practical system administration, making it an invaluable skill for both academic understanding and professional development.

---

## LINUX COMMANDS BY CATEGORY

---

## CATEGORY 1: FILE SYSTEM NAVIGATION

### 1. pwd (Print Working Directory)

**Explanation:**  
The `pwd` command displays the absolute path of your current working directory. When you open a terminal, you start in your home directory (typically `/home/username`). This command helps you identify your current location within the file system hierarchy. The absolute path always starts from the root `/` directory and shows the complete directory chain to your current position.

**Command:**
```bash
pwd
```

**Screenshot:**  
![pwd command output](./screenshots/01-pwd.png)

---

### 2. ls (List Directory Contents)

**Explanation:**  
The `ls` command lists all files and directories in your current working directory. It shows the names of files and folders but does not provide detailed information by default. This is one of the most frequently used commands for navigating the file system. You can see what's inside a directory before entering it or performing operations on its contents.

**Command:**
```bash
ls
```

**Screenshot:**  
![ls command output](./screenshots/02-ls.png)

---

### 3. ls -a (List All Files Including Hidden)

**Explanation:**  
The `ls -a` option displays all files, including hidden files and directories. In Linux, hidden files start with a dot (`.`) such as `.bashrc`, `.profile`, or `.config`. These files typically contain configuration settings for applications and the shell. The command also shows `.` (current directory) and `..` (parent directory), which are special directory entries present in every directory.

**Command:**
```bash
ls -a
```

**Screenshot:**  
![ls -a command output](./screenshots/03-ls-a.png)

---

### 4. ls -l (Long Listing Format)

**Explanation:**  
The `ls -l` command provides detailed information about files and directories. The output includes file permissions, number of hard links, owner name, group name, file size in bytes, modification date and time, and the filename. The first character indicates file type: `-` for regular file, `d` for directory, `l` for symbolic link. The next nine characters represent read (r), write (w), and execute (x) permissions for owner, group, and others.

**Command:**
```bash
ls -l
```

**Screenshot:**  
![ls -l command output](./screenshots/04-ls-l.png)

---

### 5. cd (Change Directory)

**Explanation:**  
The `cd` command changes your current working directory to a different location in the file system. You can use absolute paths (starting from `/`) or relative paths (relative to current directory). Common uses include `cd Documents` to enter a subdirectory, `cd ..` to move up one level to the parent directory, `cd ~` or just `cd` to return to your home directory, and `cd /` to go to the root directory.

**Command:**
```bash
cd Documents
cd ..
cd /home/username
cd ~
```

**Screenshot:**  
![cd command output](./screenshots/05-cd.png)

---

## CATEGORY 2: FILE AND DIRECTORY OPERATIONS

### 6. mkdir (Make Directory)

**Explanation:**  
The `mkdir` command creates new directories (folders) in the file system. You can create a single directory or multiple directories at once. Use `mkdir -p` to create parent directories if they don't exist. For example, `mkdir -p project/src/main` creates all intermediate directories. Directory names should not contain spaces unless quoted or escaped. This command is essential for organizing files into a logical structure.

**Command:**
```bash
mkdir myFolder
mkdir -p project/src/main
```

**Screenshot:**  
![mkdir command output](./screenshots/06-mkdir.png)

---

### 7. rmdir (Remove Empty Directory)

**Explanation:**  
The `rmdir` command deletes empty directories only. If a directory contains any files or subdirectories, the command will fail with an error message "Directory not empty". This safety feature prevents accidental deletion of important data. To remove directories with contents, you must use `rm -r` instead. Always verify the directory is truly empty before using this command, or check its contents with `ls`.

**Command:**
```bash
rmdir emptyFolder
```

**Screenshot:**  
![rmdir command output](./screenshots/07-rmdir.png)

---

### 8. rm (Remove Files)

**Explanation:**  
The `rm` command permanently deletes files from the file system. Unlike Windows Recycle Bin, deleted files cannot be easily recovered, so use this command carefully. You can delete multiple files at once by listing them separated by spaces. The command supports wildcards like `*` (matches any characters) and `?` (matches single character). For example, `rm *.txt` deletes all text files in the current directory.

**Command:**
```bash
rm file.txt
rm file1.txt file2.txt
rm *.log
```

**Screenshot:**  
![rm command output](./screenshots/08-rm.png)

---

### 9. rm -r (Remove Directory Recursively)

**Explanation:**  
The `rm -r` command recursively deletes directories and all their contents, including subdirectories and files. The `-r` flag stands for "recursive". This is a powerful and dangerous command because it can delete large amounts of data quickly. Use `rm -ri` for interactive mode, which prompts before each deletion. Never run `rm -rf /` or `rm -rf *` as root, as this can destroy your entire system.

**Command:**
```bash
rm -r folderName
rm -ri folderWithContent
```

**Screenshot:**  
![rm -r command output](./screenshots/09-rm-r.png)

---

### 10. touch (Create Empty File)

**Explanation:**  
The `touch` command creates new empty files or updates the access and modification timestamps of existing files. If the file doesn't exist, it creates it. If it exists, it updates its timestamp to the current time without modifying content. This is useful for creating placeholder files, testing file creation permissions, or forcing makefile rebuilds. You can create multiple files simultaneously by listing several names.

**Command:**
```bash
touch newfile.txt
touch file1.txt file2.txt file3.txt
```

**Screenshot:**  
![touch command output](./screenshots/10-touch.png)

---

### 11. cp (Copy Files and Directories)

**Explanation:**  
The `cp` command copies files or directories from one location to another. The basic syntax is `cp source destination`. To copy directories, use `cp -r` for recursive copying. The `-i` option prompts before overwriting existing files, preventing accidental data loss. Use `-v` for verbose output showing what's being copied. The command preserves file contents but creates new inodes, meaning the copy is independent of the original.

**Command:**
```bash
cp source.txt destination.txt
cp file.txt /home/user/Documents/
cp -r folder1 folder2
```

**Screenshot:**  
![cp command output](./screenshots/11-cp.png)

---

### 12. mv (Move or Rename Files)

**Explanation:**  
The `mv` command serves two purposes: moving files/directories to different locations or renaming them. Unlike `cp`, `mv` doesn't create a duplicate; it changes the file's location or name in the file system. The operation is instantaneous within the same file system because it only updates directory entries, not actual data. Use `mv -i` for interactive mode to prevent accidental overwrites. Moving across different file systems actually copies and deletes the original.

**Command:**
```bash
mv oldname.txt newname.txt
mv file.txt /home/user/Documents/
mv folder1 folder2
```

**Screenshot:**  
![mv command output](./screenshots/12-mv.png)

---

### 13. locate (Find Files by Name)

**Explanation:**  
The `locate` command quickly searches for files across the entire file system by querying a pre-built database. It's much faster than `find` because it doesn't search the file system in real-time. The database is updated periodically (usually daily) using `updatedb` command. Use `locate -i` for case-insensitive search. Since it relies on a database, recently created files might not appear until the next database update. Run `sudo updatedb` to manually update the database.

**Command:**
```bash
locate filename
locate -i document
sudo updatedb
```

**Screenshot:**  
![locate command output](./screenshots/13-locate.png)

---

### 14. find (Search Files and Directories)

**Explanation:**  
The `find` command searches for files and directories in real-time based on various criteria like name, size, type, modification time, and permissions. Unlike `locate`, it searches the actual file system, so it finds recently created files but is slower. Syntax: `find /path/ -name "pattern"`. Use `-type f` for files only, `-type d` for directories, `-size +100M` for files larger than 100MB, and `-mtime -7` for files modified in last 7 days. It can execute commands on found files using `-exec`.

**Command:**
```bash
find /home -name "*.txt"
find . -type f -size +10M
find /var/log -name "*.log" -mtime -7
find . -name "*.tmp" -delete
```

**Screenshot:**  
![find command output](./screenshots/14-find.png)

---

## CATEGORY 3: FILE VIEWING AND EDITING

### 15. cat (Concatenate and Display File)

**Explanation:**  
The `cat` command displays the entire content of one or more files on the terminal. It reads files sequentially and outputs them to standard output. You can concatenate multiple files with `cat file1.txt file2.txt > combined.txt`. It's useful for viewing short files, but for large files, consider using `less` or `more` for paginated viewing. The command can also create files: `cat > newfile.txt` lets you type content and save it with Ctrl+D.

**Command:**
```bash
cat filename.txt
cat file1.txt file2.txt
```

**Screenshot:**  
![cat command output](./screenshots/15-cat.png)

---

### 16. nano (Text Editor)

**Explanation:**  
`nano` is a simple, user-friendly command-line text editor, ideal for beginners. It displays available commands at the bottom of the screen where `^` means Ctrl key. Common commands include `Ctrl+O` to save (write out), `Ctrl+X` to exit, `Ctrl+K` to cut line, `Ctrl+U` to paste, and `Ctrl+W` to search. Unlike `vi/vim`, nano doesn't have different modes, making it more intuitive. It's perfect for quick edits to configuration files or scripts.

**Command:**
```bash
nano filename.txt
```

**Screenshot:**  
![nano editor interface](./screenshots/16-nano.png)

---

### 17. vi/vim (Advanced Text Editor)

**Explanation:**  
`vi` (Visual Editor) and its improved version `vim` (Vi IMproved) are powerful modal text editors available on virtually all Unix systems. Vi operates in different modes: Normal mode (for navigation and commands), Insert mode (for typing text, entered with `i`), and Command mode (entered with `:` for saving/quitting). Save and quit with `:wq`, quit without saving with `:q!`. Despite its steep learning curve, vi is essential for system administrators and when graphical environments are unavailable.

**Command:**
```bash
vi filename.txt
vim filename.txt
```

**Screenshot:**  
![vim editor interface](./screenshots/17-vim.png)

---

### 18. echo (Display Text or Variables)

**Explanation:**  
The `echo` command prints text or variable values to the terminal. It's commonly used in shell scripts to display messages, show variable contents, or create files with content using redirection. Use `echo $VARIABLE` to display environment variable values. The command supports escape sequences with `echo -e` option, such as `\n` for newline and `\t` for tab. Redirection operators `>` (overwrite) and `>>` (append) can write output to files.

**Command:**
```bash
echo "Hello, World!"
echo $HOME
echo -e "Line1\nLine2"
echo "Text content" > file.txt
```

**Screenshot:**  
![echo command output](./screenshots/18-echo.png)

---

## CATEGORY 4: FILE PERMISSIONS AND OWNERSHIP

### 19. chmod (Change File Permissions)

**Explanation:**  
The `chmod` command modifies file permissions in Linux, controlling read (r=4), write (w=2), and execute (x=1) access for owner, group, and others. Use numeric mode: `chmod 755 file` sets rwxr-xr-x (owner: full access, group/others: read and execute). Use symbolic mode: `chmod u+x file` adds execute permission for user. Understanding permissions is crucial for system security and file management. Execute permission on directories allows entering them.

**Command:**
```bash
chmod 755 script.sh
chmod u+x file.txt
chmod -R 644 folder/
```

**Screenshot:**  
![chmod command output](./screenshots/19-chmod.png)

---

### 20. chown (Change Ownership)

**Explanation:**  
The `chown` command changes file and directory ownership. Linux assigns an owner and group to every file. Format: `chown user:group filename`. Only root can change ownership to different users (requires `sudo`). Use `chown -R` for recursive changes on directories. For example, `sudo chown john:developers project/` assigns ownership of project directory to user john and group developers. This is essential for multi-user environments and proper access control.

**Command:**  
```bash
sudo chown username filename
sudo chown user:group filename
sudo chown -R user:group directory/
```

**Screenshot:**  
![chown command output](./screenshots/20-chown.png)

---

## CATEGORY 5: SYSTEM INFORMATION

### 21. uname -a (System Information)

**Explanation:**  
The `uname` command displays system information. The `-a` option shows all available information including kernel name (Linux), network hostname, kernel release version, kernel version with build date, machine hardware name (architecture like x86_64), processor type, and operating system name. This information is crucial for determining system compatibility, debugging, and understanding the OS environment. Different options like `-r` (kernel release) or `-m` (machine hardware) show specific details.

**Command:**
```bash
uname -a
uname -r
uname -m
```

**Screenshot:**  
![uname -a command output](./screenshots/21-uname.png)

---

### 22. whoami (Current User Identity)

**Explanation:**  
The `whoami` command displays the username of the current effective user. It's simple but useful in scripts to determine who is running the script, especially when switching users with `su` or `sudo`. The command helps verify your identity after using `su` to switch users or when running automated scripts that need to check user context. It returns only the username, unlike `id` which shows user ID, group ID, and group memberships.

**Command:**
```bash
whoami
```

**Screenshot:**  
![whoami command output](./screenshots/22-whoami.png)

---

### 23. id (User and Group Information)

**Explanation:**  
The `id` command displays user identity information including user ID (UID), group ID (GID), and all group memberships. It shows both numeric IDs and names. Use `id` for current user, `id username` for specific user, `id -u` for user ID only, `id -g` for primary group ID, and `id -G` for all group IDs. This information is crucial for understanding file permissions, as access control is based on UIDs and GIDs. The command helps troubleshoot permission issues and verify user account configuration.

**Command:**
```bash
id
id username
id -u
id -gn
```

**Screenshot:**  
![id command output](./screenshots/23-id.png)

---

### 24. which (Locate Command Binary)

**Explanation:**  
The `which` command shows the full path of shell commands by searching directories listed in the PATH environment variable. It helps identify which executable will run when you type a command, useful when multiple versions exist. For example, `which python` might show `/usr/bin/python`. If a command isn't found, which returns nothing and exits with non-zero status. This is essential for troubleshooting command conflicts and understanding your system's executable locations.

**Command:**
```bash
which python
which ls
which java
```

**Screenshot:**  
![which command output](./screenshots/24-which.png)

---

### 25. whereis (Locate Binary, Source, and Manual)

**Explanation:**  
The `whereis` command locates the binary, source code, and manual page files for commands. It searches standard locations and is faster than `find` but less flexible. Output typically shows three paths: binary location, manual page location, and source code location (if available). For example, `whereis ls` might show: `ls: /usr/bin/ls /usr/share/man/man1/ls.1.gz`. This is useful for finding documentation and understanding program installation locations.

**Command:**
```bash
whereis ls
whereis python
whereis gcc
```

**Screenshot:**  
![whereis command output](./screenshots/25-whereis.png)

---

## CATEGORY 6: DISK AND STORAGE MANAGEMENT

### 26. df -h (Disk Space Usage)

**Explanation:**  
The `df` (disk free) command displays file system disk space usage. The `-h` option presents information in human-readable format (KB, MB, GB) instead of raw bytes. The output shows total size, used space, available space, usage percentage, and mount point for each file system. This is essential for monitoring storage capacity, identifying full partitions, and preventing disk space issues that can cause system failures or data loss.

**Command:**
```bash
df -h
df -h /home
```

**Screenshot:**  
![df -h command output](./screenshots/26-df.png)

---

### 27. du -sh (Directory Size)

**Explanation:**  
The `du` (disk usage) command estimates file and directory space consumption. The `-s` option provides a summary (total only) instead of listing all subdirectories, while `-h` makes output human-readable. Use `du -sh *` to see sizes of all items in current directory. This command is invaluable for identifying which directories consume the most disk space, helping with cleanup and storage management. Unlike `df` which shows file system level, `du` shows directory level usage.

**Command:**
```bash
du -sh /home/username
du -sh * 
du -h --max-depth=1
```

**Screenshot:**  
![du -sh command output](./screenshots/27-du.png)

---

## CATEGORY 7: PROCESS MANAGEMENT

### 28. ps (Process Status)

**Explanation:**  
The `ps` command displays information about currently running processes. Without options, it shows processes in the current shell. Use `ps -u $USER` to see all processes belonging to your user, showing PID (Process ID), TTY (terminal), TIME (CPU time), and CMD (command name). The PID is crucial for managing processes. This command is fundamental for understanding process states, CPU time consumption, and identifying which programs are running on the system.

**Command:**
```bash
ps
ps -u $USER
ps aux
```

**Screenshot:**  
![ps command output](./screenshots/28-ps.png)

---

### 29. ps aux (Detailed Process Information)

**Explanation:**  
The `ps aux` command provides comprehensive process information for all users. Output includes USER (process owner), PID (process ID), %CPU (CPU utilization percentage), %MEM (memory usage percentage), VSZ (virtual memory size), RSS (resident set size in physical memory), TTY (controlling terminal), STAT (process state), START (start time), TIME (cumulative CPU time), and COMMAND. This detailed view is essential for system monitoring, identifying resource-hungry processes, and troubleshooting performance issues.

**Command:**
```bash
ps aux
ps aux | grep firefox
```

**Screenshot:**  
![ps aux command output](./screenshots/29-ps-aux.png)

---

### 30. top (Dynamic Process Viewer)

**Explanation:**  
The `top` command provides a real-time, dynamic view of running processes and system resource utilization. It continuously updates (default 3 seconds) showing CPU usage, memory usage, load averages, and process details sorted by CPU consumption. Press `q` to quit, `k` to kill a process, `M` to sort by memory, `P` to sort by CPU, and `h` for help. The header displays system uptime, user count, load averages, task statistics, CPU percentages, and memory/swap usage.

**Command:**
```bash
top
```

**Screenshot:**  
![top command interface](./screenshots/30-top.png)

---

### 31. htop (Interactive Process Viewer)

**Explanation:**  
`htop` is an improved, interactive alternative to `top` with a more user-friendly interface, color-coded output, and mouse support. It displays CPU cores individually, shows process tree hierarchy with `F5`, allows easy process killing, and supports vertical and horizontal scrolling. Function keys provide quick actions: F9 to kill process, F6 to sort, F4 to filter. Though not always installed by default (`sudo apt install htop`), it's preferred by many system administrators for process monitoring and management.

**Command:**
```bash
htop
```

**Screenshot:**  
![htop command interface](./screenshots/31-htop.png)

---

### 32. pstree (Process Tree)

**Explanation:**  
The `pstree` command displays running processes in a tree-like hierarchical structure, showing parent-child relationships. This visualization helps understand process spawning, identify process families, and see which processes started others. The tree starts from init/systemd (PID 1). Use `pstree -p` to include PIDs, `pstree -u` to show user transitions, and `pstree username` to show only that user's processes. This is particularly useful for understanding daemon processes and their children.

**Command:**
```bash
pstree
pstree -p
pstree username
```

**Screenshot:**  
![pstree command output](./screenshots/32-pstree.png)

---

### 33. kill (Terminate Process)

**Explanation:**  
The `kill` command sends signals to processes, typically to terminate them. The default signal is SIGTERM (15), which requests graceful termination, allowing processes to clean up. Use `kill -9 PID` (SIGKILL) to forcefully terminate unresponsive processes immediately without cleanup. Find the PID using `ps` or `top` first. Examples: `kill 1234` sends SIGTERM to process 1234, `kill -9 1234` forcefully kills it. Use `kill -l` to list all available signals.

**Command:**
```bash
kill PID
kill -9 PID
kill -15 PID
```

**Screenshot:**  
![kill command output](./screenshots/33-kill.png)

---

### 34. pkill (Kill Processes by Name)

**Explanation:**  
The `pkill` command terminates processes by name instead of PID, making it more convenient than `kill`. It sends signals to all processes matching the specified name pattern. For example, `pkill firefox` terminates all Firefox processes. Use `pkill -9 processname` for forceful termination. The `-u username` option kills processes belonging to a specific user. Be careful as it affects all matching processes simultaneously, potentially closing multiple instances.

**Command:**
```bash
pkill processname
pkill -9 firefox
pkill -u username processname
```

**Screenshot:**  
![pkill command output](./screenshots/34-pkill.png)

---

### 35. jobs (Background Jobs)

**Explanation:**  
The `jobs` command lists jobs running in the background or stopped in the current shell session. When you append `&` to a command, it runs in the background, freeing the terminal. Jobs are numbered [1], [2], etc. Use `fg %1` to bring job 1 to foreground, `bg %1` to resume stopped job 1 in background. Press Ctrl+Z to stop (suspend) a foreground job. This job control mechanism allows multitasking within a single terminal session.

**Command:**
```bash
jobs
sleep 100 &
jobs
fg %1
```

**Screenshot:**  
![jobs command output](./screenshots/35-jobs.png)

---

### 36. bg (Background Job Control)

**Explanation:**  
The `bg` command resumes suspended (stopped) jobs in the background. When you press Ctrl+Z, it suspends the current foreground job. Use `bg` to continue it in background, or `bg %jobnumber` for specific jobs. This is useful when you start a long-running process and realize you need the terminal for other tasks. Combined with `jobs` and `fg`, it provides comprehensive job control for efficient multitasking within the shell.

**Command:**
```bash
# Start a process, press Ctrl+Z to suspend
bg
bg %1
```

**Screenshot:**  
![bg command output](./screenshots/36-bg.png)

---

### 37. fg (Foreground Job Control)

**Explanation:**  
The `fg` command brings background or suspended jobs to the foreground, making them the active process that receives terminal input. Use `fg` without arguments to bring the most recent background job forward, or `fg %jobnumber` to specify which job. Once in foreground, you can interact with the process normally. This is particularly useful for text editors or interactive programs you accidentally backgrounded. You can suspend it again with Ctrl+Z if needed.

**Command:**
```bash
fg
fg %1
fg %2
```

**Screenshot:**  
![fg command output](./screenshots/37-fg.png)

---

### 38. nohup (Run Command Immune to Hangups)

**Explanation:**  
The `nohup` command runs processes that continue running even after you log out or close the terminal. It ignores the HUP (hangup) signal sent when a session terminates. Output is redirected to `nohup.out` file by default. Usage: `nohup command &` runs command in background immune to hangups. This is essential for long-running tasks on remote servers. The process becomes orphaned and continues running under the init/systemd process.

**Command:**
```bash
nohup python script.py &
nohup ./long_process > output.log 2>&1 &
```

**Screenshot:**  
![nohup command output](./screenshots/38-nohup.png)

---

## CATEGORY 8: MEMORY MANAGEMENT

### 39. free -h (Memory Usage)

**Explanation:**  
The `free` command displays system memory (RAM) and swap space usage statistics. The `-h` option shows values in human-readable format. Output includes total memory, used memory, free memory, shared memory, buffer/cache memory, and available memory. The "available" column is particularly important as it shows memory that can be made available for applications without swapping. Understanding memory usage is crucial for diagnosing performance issues and determining if additional RAM is needed.

**Command:**
```bash
free -h
free -m
```

**Screenshot:**  
![free -h command output](./screenshots/39-free.png)

---

### 40. vmstat (Virtual Memory Statistics)

**Explanation:**  
The `vmstat` command reports virtual memory statistics including processes, memory, paging, block IO, traps, and CPU activity. It provides insights into system performance and helps identify bottlenecks. The first line shows averages since boot; subsequent lines show interval statistics. Common usage: `vmstat 2 5` displays statistics every 2 seconds for 5 iterations. Key columns include r (runnable processes), free (free memory), si/so (swap in/out), bi/bo (blocks in/out), and CPU percentages.

**Command:**
```bash
vmstat
vmstat 2 5
vmstat -s
```

**Screenshot:**  
![vmstat command output](./screenshots/40-vmstat.png)

---

## CATEGORY 9: SYSTEM MONITORING AND LOGS

### 41. dmesg (Kernel Ring Buffer)

**Explanation:**  
The `dmesg` command displays messages from the kernel ring buffer, showing kernel and hardware-related messages since boot. It's invaluable for diagnosing hardware issues, driver problems, and system boot errors. Messages include device detection, driver loading, memory initialization, and hardware failures. Use `dmesg | grep -i error` to find errors, `dmesg -T` for human-readable timestamps, and `dmesg -w` to follow new messages. Root privileges may be needed for full access.

**Command:**
```bash
dmesg
dmesg | grep -i usb
dmesg -T
dmesg | tail -50
```

**Screenshot:**  
![dmesg command output](./screenshots/41-dmesg.png)

---

### 42. journalctl (System Logs)

**Explanation:**  
The `journalctl` command queries the systemd journal, displaying system and service logs. It provides centralized logging for all systemd-managed services. Use `journalctl -u service-name` to view logs for specific service, `journalctl -f` to follow logs in real-time (like tail -f), `journalctl --since "1 hour ago"` for time-based filtering, and `journalctl -p err` to show only error messages. This is essential for troubleshooting system issues, monitoring service behavior, and security auditing.

**Command:**
```bash
journalctl
journalctl -u ssh.service
journalctl -f
journalctl --since today
```

**Screenshot:**  
![journalctl command output](./screenshots/42-journalctl.png)

---

### 43. lsof (List Open Files)

**Explanation:**  
The `lsof` (List Open Files) command displays all files currently opened by processes. In Linux, "everything is a file" including regular files, directories, network sockets, pipes, and devices. This command is invaluable for troubleshooting - finding which process is using a file, identifying network connections, and diagnosing "file in use" errors. Use `lsof filename` to see which processes have a file open, `lsof -u username` for files opened by a user, `lsof -i` for network connections, and `lsof -p PID` for files opened by a specific process.

**