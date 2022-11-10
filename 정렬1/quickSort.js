const arr = [3, 2, 7, 116, 62, 235, 1, 23, 55, 77];

function quickSort(start, end) {
  if (start >= end) return;
  let pivot = arr[start];
  let l = start + 1,
    r = end;
  while (1) {
    while (pivot >= arr[l] && l <= r) l++;
    while (pivot <= arr[r] && r >= l) r--;
    if (l >= r) break;
    const tmp = arr[r];
    arr[r] = arr[l];
    arr[l] = tmp;
  }
  arr[start] = arr[r];
  arr[r] = pivot;
  quickSort(start, r);
  quickSort(r + 1, end);
}

quickSort(0, arr.length - 1);
console.log(arr);
