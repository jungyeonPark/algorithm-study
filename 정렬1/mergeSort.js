const arr = [3, 2, 7, 116, 62, 235, 1, 23, 55, 77];
const tmp = [];

function merge(start, end, mid) {
  let lIdx = start,
    rIdx = mid;
  for (let i = start; i < end; i++) {
    if (lIdx === mid) tmp[i] = arr[rIdx++];
    else if (rIdx === end) tmp[i] = arr[lIdx++];
    else tmp[i] = arr[lIdx] <= arr[rIdx] ? arr[lIdx++] : arr[rIdx++];
  }
  for (let i = start; i < end; i++) {
    arr[i] = tmp[i];
  }
}

function mergeSort(start, end) {
  if (start === end - 1) return;
  let mid = Math.floor((start + end) / 2);
  mergeSort(start, mid);
  mergeSort(mid, end);
  merge(start, end, mid);
}

mergeSort(0, arr.length);
console.log(arr);
