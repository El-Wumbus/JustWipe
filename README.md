# JustWipe

## Feature Set

* Supports overwriting an entire drive with 0s (actually removing data, not just hiding it.)
* Can overwrite a drive or partition if specified.

## How to install

To get the source code of this software you'll need the `git` version control software.
You probably already have it installed, you can check `git --version`.
If you get an error message then you must install `git` from your distro's repositories.

For the installation of this software a C compiler is required. Your distro already has one installed, it's probably `gcc`.
If not, then you need to install `gcc` You can check with `gcc --version`. If you get an error message then you must install
`gcc` from your distro's repositories.

You'll also need `make`, you likely already have this installed. You can check with `make --version`.
If you get an error message then you must install `make` from your distro's repositories.

This program is built with `glibc` in mind. If you use a different C library it may not function as expected.
This does not mean it doesn't work with other C libraries, this means i haven't confirmed functionality with
all the C libraries out there. Ensure you're using `glibc` before complaining about broken software.

Now that we have all the dependencies present we can compile the project. The following instructions assume the bash shell, though these instructions will work with the *vast* majority of linux shells (everything you're likely to use).

```bash
git clone https://github.com/El-Wumbus/JustWipe.git
cd JustWipe
sudo make install
```

## Usage

```bash
# To wipe a partition. replace sdXY with the partition you want to wipe.
# Ensure you aren't trying to wipe a mounted drive
sudo jwipe /dev/sdXY -v

# To wipe an entire drive
sudo jwipe /dev/sdX -v
```

### Flags & Options

| Flag |Effect                                                 |
|------|-------------------------------------------------------|
| `-v` | Enables Verbose Ouptut (Logs every 512 bytes written) |
|`-h`  | Display help information and exit                     |

#### Example

Verbose:

```shell
$ sudo jwipe /dev/sdc -v
Write zeros to drive [0]
Exit [1]
Enter menu choice: 0
Are you sure you want to wipe the drive? (y/n): y
Writing 0s to /dev/sdc
...
Bytes written: 130560
Bytes written: 131072
Bytes written: 131584
Bytes written: 132096
Bytes written: 132608
Bytes written: 133120
...
```

Non-Verbose:

```shell
$ sudo jwipe /dev/sdc
Write zeros to drive [0]
Exit [1]
Enter menu choice: 0
Are you sure you want to wipe the drive? (y/n): y
Writing 0s to /dev/sdc (Use -v to see progress)
```

## Contributing

* Check the issues (if there are any), it's a good place to start when you don't know what to do.
* Fork the repository and create pull requests to this repository.
* Don’t change the formatting - Dont reformat or otherwise change the formatting of source code or documentation in the repo. Use the same formatting as the rest of the codebase.
* Make documentation - If adding features or otherwise changing the user experience create documentation regarding the added or changed features.
* Use space only indentation in all source code files with the sole execption of Makefile - Do not use tabs or any form of indentation other than spaces. Use 2 space indentation.

## LICENSE

[![GNU LGPLv3 Image](https://www.gnu.org/graphics/lgplv3-147x51.png)](https://www.gnu.org/licenses/lgpl-3.0.html)  

Just Wipe is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation;
either version 3 of the License, or (at your option) any later version.
