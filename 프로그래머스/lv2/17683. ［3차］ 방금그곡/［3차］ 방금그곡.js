function solution(m, musicinfos) {
    m = m.replaceAll('C#', 'c').replaceAll('D#', 'd').replaceAll('F#', 'f').replaceAll('G#', 'g').replaceAll('A#', 'a');

    return musicinfos.reduce((acc, data) => {
        const [start, end, title, tempSheet] = data.split(',');
        const getMin = (time) => parseInt(time[0]) * 60 + parseInt(time[1]);
        const playTime = getMin(end.split(':')) - getMin(start.split(':'));
        const sheet = tempSheet.replaceAll('C#', 'c').replaceAll('D#', 'd').replaceAll('F#', 'f').replaceAll('G#', 'g').replaceAll('A#', 'a');
        const newSheet = sheet.repeat(Math.floor(playTime / sheet.length)) + sheet.substr(0, Math.floor(playTime % sheet.length));

        if (newSheet.includes(m) && playTime > acc.TIME) acc = { TITLE: title, TIME: playTime };
        return acc;
    }, { TITLE: "(None)", TIME: 0 }).TITLE;
}
