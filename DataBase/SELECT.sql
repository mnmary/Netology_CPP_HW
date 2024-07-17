SELECT name, timeof/60 as timeof_in_min 
	FROM public.track
	ORDER BY timeof desc
	LIMIT 1;

SELECT name
	FROM public.track
	WHERE timeof >=3.5*60;

SELECT name 
	FROM public.collection
	WHERE yearof>=2018 AND yearof<=2020;

SELECT name 
	FROM public.artist
	WHERE NOT (name like '% %');

SELECT name 
	FROM public.track
	WHERE (name like '%my%' or name like '%мой%' ); 

-- ----------

SELECT genre.name, COUNT(genre_artist.artistid) as artist_count
FROM public.genre_artist AS genre_artist
LEFT JOIN public.genre AS genre ON genre.id = genre_artist.genreid
GROUP BY genre.name;

SELECT album.name, COUNT(track.id)
FROM public.track as track
LEFT JOIN public.album as album ON album.id = track.albumid
WHERE album.yearof >= 2019 AND album.yearof<2021
GROUP BY album.name;


SELECT album.name, AVG(track.timeof)/60
FROM public.track as track
LEFT JOIN public.album as album ON album.id = track.albumid
GROUP BY album.name;

SELECT artists.artistList, artists.cntAlbum
FROM
	(
	SELECT artist.name as artistList,
	COUNT(album.name) as cntAlbum
	FROM public.artist_album as artist_album
	LEFT JOIN public.artist as artist ON artist.id = artist_album.artistid
	LEFT JOIN public.album as album ON album.id = artist_album.albumid AND album.yearof = 2020
	GROUP BY artist.name
	) as artists
WHERE artists.cntAlbum=0;

SELECT collection.name, track.name, album.name, artist.name 
FROM collection_track as collection_track
LEFT JOIN public.collection as collection ON collection.id = collection_track.collectionid
LEFT JOIN public.track as track on track.id = collection_track.trackid
left join public.album as album ON album.id = track.albumid
left join public.artist_album as artist_album ON artist_album.albumid = album.id
left join public.artist as artist ON artist.id = artist_album.artistid

WHERE artist.name = 'АНДРЕЙ ПЕТРОВ';

-- ---------------

SELECT * FROM
	(
	SELECT album.name as albumName, Count(genre_artist.genreid) as genreCnt
	FROM public.genre_artist as genre_artist
	LEFT JOIN public.artist as artist ON artist.id = genre_artist.artistid
	LEFT JOIN public.artist_album as artist_album ON artist_album.artistid = artist.id
	LEFT JOIN public.album as album ON album.id = artist_album.albumid
	GROUp BY album.name
	) as genreList
WHERE (genreList.genreCnt) > 1;

SELECT track.name, collection_track.collectionid FROM public.track
LEFT JOIN public.collection_track as collection_track ON track.id = collection_track.trackid
WHERE collection_track.collectionid IS NULL;

SELECT artist.name, track.timeof FROM public.track
LEFT JOIN public.album as album on track.albumid = album.id
LEFT JOIN public.artist_album as artist_album on artist_album.albumid = album.id
LEFT JOIN public.artist as artist on artist_album.artistid = artist.id 
WHERE track.timeof = 
	(
	SELECT min(timeof) FROM public.track
	);

SELECT DISTINCT album.name FROM public.album
LEFT JOIN public.track on track.albumid = album.id
WHERE track.albumid IN 
	(
    SELECT albumid 
	FROM public.track
    GROUP BY albumid
    HAVING count(albumid) = 
		(
         SELECT count(id)
         FROM public.track
         GROUP BY albumid
         ORDER BY count
         LIMIT 1
		)
	)


