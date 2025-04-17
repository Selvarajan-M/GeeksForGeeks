//{ Driver Code Starts
// Initial Template for C
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// } Driver Code Ends

// User function Template for C

// Function to check if the array is sorted
int largest(int arr[], int n) {
    int largest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest)
        largest=arr[i];
    }
    return largest;
}


//{ Driver Code Starts.

int main() {
    char ts[1001];
    fgets(ts, sizeof(ts), stdin); // Read the number of test cases
    int t = atoi(ts);

    while (t--) {
        char *line = NULL;
        size_t len = 0;
        long read = getline(&line, &len, stdin); // Replacing ssize_t with long

        int *nums = (int *)malloc(
            1000000 *
            sizeof(int)); // Dynamically allocate memory for up to 1e6 integers
        int n = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            nums[n++] =
                atoi(token); // Convert each token to an integer and store in nums
            token = strtok(NULL, " ");
        }
        int brr[n];
        for (int i = 0; i < n; i++) {
            brr[i] = nums[i];
        }

        int ans = largest(brr, n);
        printf("%d\n", ans); // Output result
        printf("%s\n", "~"); // Output result

        free(nums); // Free dynamically allocated memory
        free(line); // Free dynamically allocated memory for the input line
    }

    return 0;
}

// } Driver Code Ends