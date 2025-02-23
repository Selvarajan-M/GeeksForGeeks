//{ Driver Code Starts
// Initial Template for javascript

"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => { inputString += inputStdin; });

process.stdin.on("end", (_) => {
    inputString =
        inputString.trim().split("\n").map((string) => { return string.trim(); });

    main();
});

function readLine() { return inputString[currentLine++]; }

/* Function to print an array */
function printArray(arr, size) {
    let i;
    let s = "";
    for (i = 0; i < size; i++) {
        if (arr[i] === -0) arr[i] = 0;
        s += arr[i] + " ";
    }
    console.log(s);
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for (; i < t; i++) {
        let arr = readLine().trim().split(" ").map((x) => parseInt(x));
        let obj = new Solution();
        obj.bubbleSort(arr);
        printArray(arr, arr.length);
    }
}
// } Driver Code Ends


// User function Template for javascript

/**
 * @param {number[]} arr
 */
class Solution {
    // Function to sort the array using bubble sort algorithm.
    bubbleSort(arr) {
        // code here
        let swapped
        do{
            swapped=false;
            for(let i=0;i<arr.length-1;i++){
                if(arr[i]>arr[i+1]){
                    let temp=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                    swapped=true;
                }
            }
        }while(swapped)
    }
}
