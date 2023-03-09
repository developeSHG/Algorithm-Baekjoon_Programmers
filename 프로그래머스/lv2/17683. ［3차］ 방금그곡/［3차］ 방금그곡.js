function solution(m, musicinfos) {
    m = m.replaceAll('C#', 'c').replaceAll('D#', 'd').replaceAll('F#', 'f').replaceAll('G#', 'g').replaceAll('A#', 'a');

    return musicinfos.reduce((acc, data) => {
        const [start, end, TITLE, tempSheet] = data.split(',');
        const getMin = (time) => parseInt(time[0]) * 60 + parseInt(time[1]);
        const TIME = getMin(end.split(':')) - getMin(start.split(':'));
        const sheet = tempSheet.replaceAll('C#', 'c').replaceAll('D#', 'd').replaceAll('F#', 'f').replaceAll('G#', 'g').replaceAll('A#', 'a');
        const newSheet = sheet.repeat(Math.floor(TIME / sheet.length)) + sheet.substr(0, Math.floor(TIME % sheet.length));

        return (newSheet.includes(m) && TIME > acc.TIME) ? { TITLE, TIME } :acc;
    }, { TITLE: "(None)", TIME: 0 }).TITLE;
}
