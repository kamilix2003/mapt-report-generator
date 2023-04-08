# Report baker for MAPT

## Requierments
- python installed
- g++ installed

## How to bake your report
all files have to be in the current directory
```shell
./reportbaker -f [source_files] -l [lab_number] -lm [lab_msg] -em [ex_msg]
```
when no files given program will use all files with `.cpp` and `.py` extentions in the current directory. 
default `lab_msg = Laboratory`, `ex_msg = Exercise`
