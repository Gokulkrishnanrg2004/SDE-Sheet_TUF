/*
 Count Inversions
Moderate
80/80
Average time to solve is 40m
Contributed by
707 upvotes
Asked in companies
Problem statement
For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.

An inversion is defined for a pair of integers in the array/list when the following two conditions are met.

A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').
Detailed explanation ( Input/output format, Notes, Images )
*/
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n)
{
    long long count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] > arr[j]) count++;
        }
    }
    return count;
}
