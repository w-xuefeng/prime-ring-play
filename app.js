var n = 30;
var a = new Array(100).fill(0);
var visit = new Array(100).fill(0);
const check = k => {
  let i
  let n
  n = parseInt(Math.sqrt(k));
  for (i = 2; i <= n; i++) {
    if (k % i == 0) {
      return 0;
    }
  }
  return 1;
}
const dfs = step => {
  if (step == n && check(a[0] + a[n - 1]) == 1) {
    let temp = []
    for (let i = 0; i < n; i++) {
      temp.push(a[i])
    }
    console.log(...temp);
    return;
  } else {
    for (let i = 2; i <= n; i++) {
      if (visit[i] == 0 && check(i + a[step - 1]) == 1) {
        a[step] = i;
        visit[i] = 1;
        dfs(step + 1);
        visit[i] = 0;
      }
    }
  }
}
const main = () => {
  a[0] = 1;
  visit[1] = 1;
  dfs(1);
  return 0;
}

main();