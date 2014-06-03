<div class="clickable">CLICKABLE</div>

<div class="introduction">

	<noscript>
		<img class="introduction-image" src="<%= obj.pathStatic %>/<%= obj.vocab_dir %><%= intro.image.src %>" alt="<%= intro.image.alt %>" width="640" height="360"  />
	</noscript>
	<div class="delayed-image-load introduction-image" data-src="<%= obj.pathStatic %>/<%= obj.vocab_dir %><%= intro.image.src %>" data-width="640" style="width: 100%;" data-alt="<%= intro.image.alt %>"></div> 

	<div class="introduction-textwrapper">
		<div class="introduction-textwrapper__text">

			<% _.forEach(intro.text, function (text) { %>
				<p><%= text %></p>
			<% }) %>
			
			<div class="introduction-textwrapper__launcher_icon"></div>
		</div>
	</div>

</div>