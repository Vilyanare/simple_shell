## Github Collaboration Order of Commands

#### Written by Kiren, revised by Jacob

1. On github, create an "alpha" branch that is a copy of master

2. :~/ur_dir$ git pull origin alpha

3. :~/ur_dir$ git checkout -b feauture

4. Program! and make changes to your local feature

5. :~/ur_dir$ git add file1 file2 ...

6. :~/ur_dir$ git commit -m "message"

7. :~/ur_dir$ git push origin feature

8. On github, create a pull request with "alpha" as "base" and "feautre" as "compare"

9. Have other person review and merge "feature" to alpha

10. :~/ur_dir$ git checkout alpha

REPEAT STEPS 2-10 throughout the project

11. :~/ur_dir$ On github, create a pull request with "master" as "base" and "alpha" as "compare"

12. Finally, merge to master on github.

#### Other git commands

:~/ur_dir$ git branch   *this will tell you which branch you're on*