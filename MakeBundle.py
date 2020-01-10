import os
import pathlib
import subprocess

dependencies_file = "Dependencies.txt" # File for ldd output
libs_dir = "DMCompanion_bundle" # Copy libraries to this directory (relative to CWD)
executable = "DMCompanion"
execution_script = "DMCompanion.sh"

def generate_dependencies():
    cmd = "ldd %s" % executable
    output = subprocess.check_output(cmd, shell=True)
    output = output.decode('utf-8')
    with open(dependencies_file, 'w') as f:
        f.write(output)


def file_copy(src, dst):
    cmd = "cp %s %s" % (src, dst)
    print(cmd) # Optional, but this shows what libraries got copied
    subprocess.check_call(cmd, shell=True)


def relative_copy(abs_path, dst_dir=libs_dir):
    name = pathlib.Path(abs_path).name
    rel_dst = os.path.join(dst_dir, name)
    file_copy(abs_path, rel_dst)


def copy_deps():

    # Create the libraries directory if necessary
    if not os.path.isdir(libs_dir):
        os.mkdir(libs_dir)

    # Iterate through the dependencies file and copy the necessary libraries
    with open(dependencies_file, 'r') as f:
        line_ct = -1
        for x in f:
            line_ct += 1
            data = x.split()

            # The default case
            if len(data) == 4:
                relative_copy(data[2])

            # Otherwise, we're (probably) dealing with the linker or linux-vdso
            # If it's vdso, just skip
            # But we DO want to copy the linker
            elif len(data) == 2:
                if data[0].startswith("linux-vdso"):
                    continue
                elif data[0].startswith("/lib64/ld-linux"):
                    relative_copy(data[0])

            # Otherwise, there's something up
            else:
                print("ERROR with %s line #%d: %s" % (dependencies_file, line_ct, x))
                exit(1)

    # Copy the executable and the execution script into the bundle directory
    file_copy(executable, os.path.join(libs_dir, executable))
    file_copy(execution_script, os.path.join(libs_dir, execution_script))

# Main routine
if __name__ == "__main__":
    generate_dependencies()
    copy_deps()