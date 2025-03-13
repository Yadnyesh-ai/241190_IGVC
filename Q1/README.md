This question is not completely solved bcoz of the time limit (I didnt had laptop so I could do the work only for like 10 hrs)
The basic Idea is:
update all 0s of matrix with the number representing with minimum number of turns required to get there, which can be found as we go through the algorythm. The code has some fixable flaws in this regards.
then trace back the numbers such that our flag goes from the element in matrix which has largest number of turns (the endpoint which is same as starting point) to minimum surrounding number in the 3*3 matrix around it and it eventually goes to the starting point along the path we want it to.
