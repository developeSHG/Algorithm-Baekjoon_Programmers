function solution(m, musicinfos) {
    m = m.replaceAll('C#', 'c').replaceAll('D#', 'd').replaceAll('F#', 'f').replaceAll('G#', 'g').replaceAll('A#', 'a');

    return musicinfos.reduce((acc, data) => {
        const [start, end, title] = data.split(',');
        const getMin = (time) => parseInt(time[0]) * 60 + parseInt(time[1]);
        const playTime = getMin(end.split(':')) - getMin(start.split(':'));
        const sheet = data.split(',')[3].replaceAll('C#', 'c').replaceAll('D#', 'd').replaceAll('F#', 'f').replaceAll('G#', 'g').replaceAll('A#', 'a');
        let newSheet = '';
        
        for (let i = 0; i < Math.floor(playTime / sheet.length); ++i)
            newSheet += sheet;
        for (let i = 0; i < Math.floor(playTime % sheet.length); ++i)
            newSheet += sheet[i];

        if (newSheet.includes(m) && playTime > acc.TIME) acc = { TITLE: title, TIME: playTime };
        return acc;
    }, { TITLE: "(None)", TIME: 0 }).TITLE;
}
