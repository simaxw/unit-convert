# Install Qt Environment

## Download Prerequisites

- [Git](https://github.com/git-for-windows/git/releases/download/v2.46.0.windows.1/PortableGit-2.46.0-64-bit.7z.exe)
- [CMake](https://github.com/Kitware/CMake/releases/download/v3.30.1/cmake-3.30.1-windows-x86_64.zip)
- [MinGW](https://github.com/niXman/mingw-builds-binaries/releases/download/13.2.0-rt_v11-rev1/x86_64-13.2.0-release-posix-seh-msvcrt-rt_v11-rev1.7z)
- [Qt6 - qtbase](https://download.qt.io/online/qtsdkrepository/windows_x86/desktop/qt6_672/qt.qt6.672.win64_mingw/6.7.2-0-202406110335qtbase-Windows-Windows_10_22H2-Mingw-Windows-Windows_10_22H2-X86_64.7z)
- [Qt6 - qt5compat](https://download.qt.io/online/qtsdkrepository/windows_x86/desktop/qt6_672/qt.qt6.672.qt5compat.win64_mingw/6.7.2-0-202406110335qt5compat-Windows-Windows_10_22H2-Mingw-Windows-Windows_10_22H2-X86_64.7z)
- [Qt6 - declarative](https://download.qt.io/online/qtsdkrepository/windows_x86/desktop/qt6_672/qt.qt6.672.win64_mingw/6.7.2-0-202406110335qtdeclarative-Windows-Windows_10_22H2-Mingw-Windows-Windows_10_22H2-X86_64.7z)
- [Ninja](https://github.com/ninja-build/ninja/releases/download/v1.12.1/ninja-win.zip)

## Create Directory

In order to have everything in one place I would recommend to create one
directory in drive C called `devenv` for *development environment*.
Under this directory all software components mentioned above are
extracted to.

Let's begin:

## Install Git

Even though the PortableGit package downloads as an .exe it can also be
unpacked with 7Zip. Once you have done that create a directory named
`git` under `C:\devenv` and move the extracted contents into that
directory. You should now have `C:\devenv\git\bin\git.exe`.

## Install CMake

Create a new directory `C:\devenv\cmake` and unpack the contents to
`C:\devenv\cmake`.

## Install MinGW, Ninja, Qt

Unfortunately the Qt Company does not provide offline installers any
more and the online installer needs you to register an account. So we do
a manual install here.

Create a new directory `C:\devenv\mingw` and unpack the contents of
MinGW, Ninja and Qt all into this directory.

The MinGW archive has an subdirectory called `mingw64` change into this
first and extract the folders to `C:\devenv\mingw`.

The Ninja archive contains just one executable. Copy it to
`C:\devenv\mingw\bin`.

Copy the files of all Qt-archives from
`6.7.2\mingw_64` to `C:\devenv\mingw`.

## Adjust PATH Environment Variable

Open the Windows System Settings and add the following Path entries to
the list of the System Path Environment Variable:

- c:\devenv\mingw\bin
- c:\devenv\cmake\bin
- c:\devenv\git\bin

If you can't or don't want to change the environment you can also create a file `env.bat` in `c:\devenv` to set the Path like this:

```
@echo off

set PATH=%PATH%;c:\devenv\cmake\bin;c:\devenv\git\bin;c:\devenv\mingw\bin
echo Path set
```
Of course you have to run this script every time you open a CMD.

Open a new cmd and verify the following commands work:

- g++ --version
- gcc --version
- cpp --version
- cmake --version
- rcc --version
- moc --version
- ninja --version
- git --version

# Build Unit Convert

The project is hosted on github. The clone URL is
https://github.com/simaxw/unit-convert.git

Create a new directory under `c:\devenv` called `repos`.

Change into that directory and clone the repository:

```
> git clone https://github.com/simaxw/unit-convert.git
Cloning into 'unit-convert'...
remote: Enumerating objects: 885, done.
remote: Counting objects: 100% (885/885), done.
remote: Compressing objects: 100% (375/375), done.
remote: Total 885 (delta 482), reused 885 (delta 482), pack-reused 0
Receiving objects: 100% (885/885), 1.90 MiB | 5.51 MiB/s, done.
Resolving deltas: 100% (482/482), done.
```

Change into the unit-convert directory and create a build directory:

```
> cd unit-convert
> mkdir build
> cd build
```

Instruct cmake to create the Ninja build files. The current CMake
instructions are good for both platforms, linux and win32.

Now run the build:

```
> cmake -G Ninja ..
-- The CXX compiler identification is GNU 13.2.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/devenv/mingw/bin/c++.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Performing Test HAVE_STDATOMIC
-- Performing Test HAVE_STDATOMIC - Success
-- Found WrapAtomic: TRUE
-- Could NOT find WrapVulkanHeaders (missing: Vulkan_INCLUDE_DIR)
-- Configuring done (10.2s)
-- Generating done (0.4s)
-- Build files have been written to: C:/devenv/repos/unit-convert/build
```
Errors about not finding Vulkan Headers can be ignored.

Build the project:
```
> ninja
```

Start the application:

```
> unitconvert
```

## Deploying To Machines Without Qt

If you want to deploy your application on other Windows machines read
[Deploying Windows Applications](https://wiki.qt.io/Deploying_Windows_Applications).

For the unit-convert application you need the following files:

```
data.rcc
libgcc_s_seh-1.dll
libstdc++-6.dll
libwinpthread-1.dll
[platforms]
  qwindows.dll
Qt6Core.dll
Qt6Core5Compat.dll
Qt6Gui.dll
Qt6Network.dll
Qt6Qml.dll
Qt6Widgets.dll
unitconvert.exe
```
