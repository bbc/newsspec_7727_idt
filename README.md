# Newsspec-7727

IDT-friendly version of the Nelson Mandela Timeline - moved into the iFrame Scaffold

## Create your own timeline

Read the section "Two versions of the timeline". You may be looking for a different version of this timeline.

## Two versions of the timeline

This project was built with reusability in mind. 

The plan is for timelines to be incorporated into IDT. As such, this project was initially developed in an IDT-friendly way, with a cohesive JSON structure and rendering script. You are looking at that version.

If you're looking for the version of the timeline that we can use with our current Google spreadsheet vocabs setup, [you'll want to go here!](https://github.com/BBCVisualJournalism/newsspec_7727)

## Issues

Debug mode is not available due to the changes in architecture required in this project (e.g. missing jQuery version).
Videos will not work in the stage environment, unless the video has a matching MAP page on stage (unlikely). Similarly, placeholder images for videos will not load in the local environment because of cross-domain issues. Both should work in tandem on live.
Videos require two clicks on mobile devices, owing to data-usage restrictions that prevent autoplay from working.

## Changes to the architecture

### HTML5 support

We should start using semantic markup, but I found that in old versions of IE the buttons and inputs nested inside them would not work, and elements wouldn't render at all in even older versions of IE! Legacy support for semantic elements required a change to the architecture.

#### Changes to /source/tmpl/includes/top.tmpl

Line 179 - added a [HTML5 shiv](https://code.google.com/p/html5shiv/).

### Video

Getting video working was a pain. Bump requires the full-fat jQuery library 1.9, so I took the jquery-1.9.1 that is in the BBC shared assets and named it jquery-1.9.1-version_for_bump.js. As BUMP video is required across all browsers, it made no sense to pull in additional versions of jQuery for legacy IE and/or modern browsers, so I stripped out the dual jQuery setup and now all browsers pull in the BUMP-compatible version of jQuery.

I have outlined the changes below:

#### Changes to /tasks/

Line 17 of js.js - removed the call to requirejs:jquery2.

In require.js, removed the jquery2 task, changed the output from all-html5.js to all.js, renamed version of jquery on line 24.

#### Changes to /source/js/lib/

Wherever there was a dependency on 'jquery' I changed the dependency to 'jquery-1.9'. These files were:

* news_special/bootstrap.js
* news_special/iframemanager__frame.js
* news_special/imager.js
* vendors/jquery/pubsub.js

#### Changes to /source/tmpl/includes/bottom.tmpl

Line 45 - point to the all-encompassing JS file "all.js", which is for both modern AND legacy browsers.

Line 48 - hardcode the version of jQuery that is used in debug mode.

## iFrame scaffold

This project was built using the iFrame scaffold v1.3

## License
Copyright (c) 2014 BBC
