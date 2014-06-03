<div class="carousel_large_container">

	<nav class="carousel_nav_container carousel_nav_container--large">
		<button class="carousel_nav carousel_nav--prev">&lt;</button>
		<button class="carousel_nav carousel_nav--next">&gt;</button>
	</nav>

	<ul class="carousel_large">

		<%
			_.forEach(panels, function (panel) {

				panel = panel.panel;
		%>

			<li class="carousel_large__item">

				<div class="carousel_large__item-textwrapper">
					<h2 class="carousel_large__item-heading"><%= panel.title %></h2>

					<div class="carousel_large__item-text">
						<% _.forEach(panel.text, function (text) { %>
							<p><%= text %></p>
						<% }) %>
					</div>
				</div>

				<div class="carousel_large__item-media">

					<% 
					if (panel.map) { 
					%>
						<a class="carousel_large__item-media__playlist" href="<%= panel.map.page %>" data-playlist="<%= panel.map.playlist %>" data-holding-image="<%= obj.pathStatic %>/<%= obj.vocab_dir %><%= panel.image.src %>">
							<% renderImage(panel) %>
						</a>
					<%
					} else {
						renderImage(panel);
					}
					%>

				</div>

			</li>
		
		<% }) %>
		
	</ul>

</div>

<%
	function renderImage(panel) {
%>
	<noscript>
		<img class="carousel_large__item-media__image" src="<%= obj.pathStatic %>/<%= obj.vocab_dir %><%= panel.image.src %>" alt="<%= panel.image.alt %>" width="640" height="360"  />
	</noscript>

	<div class="delayed-image-load carousel_large__item-media__image" data-src="<%= obj.pathStatic %>/<%= obj.vocab_dir %><%= panel.image.src %>" data-width="320" style="width: 100%;" data-alt="<%= panel.image.alt %>"></div> 
	
	<% if(panel.map && panel.map.overlay) { %>
		<div class="carousel_large__item-media__image_overlay--<%= panel.map.overlay %>"></div>
	<% } %>
<%
	}
%>